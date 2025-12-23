;******************************************************************************
;* x86 optimizations for PNG decoding
;*
;* Copyright (c) 2008 Loren Merritt <lorenm@u.washington.edu>
;* Copyright (c) 2012 Ronald S. Bultje <rsbultje@gmail.com>
;*
;* This file is part of FFmpeg.
;*
;* FFmpeg is free software; you can redistribute it and/or
;* modify it under the terms of the GNU Lesser General Public
;* License as published by the Free Software Foundation; either
;* version 2.1 of the License, or (at your option) any later version.
;*
;* FFmpeg is distributed in the hope that it will be useful,
;* but WITHOUT ANY WARRANTY; without even the implied warranty of
;* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;* Lesser General Public License for more details.
;*
;* You should have received a copy of the GNU Lesser General Public
;* License along with FFmpeg; if not, write to the Free Software
;* 51, Inc., Foundation Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
;******************************************************************************

%include "libavutil/x86/x86util.asm"

SECTION_RODATA

cextern pw_255

SECTION .text

INIT_XMM sse2
cglobal add_bytes_l2, 4, 6, 2, dst, src1, src2, wa, w, i
%if ARCH_X86_64
    movsxd             waq, wad
%endif
    xor                 iq, iq

    ; vector loop
    mov                 wq, waq
    and                waq, ~(mmsize*2-1)
    jmp .end_v
.loop_v:
    movu                m0, [src2q+iq]
    movu                m1, [src2q+iq+mmsize]
    paddb               m0, [src1q+iq]
    paddb               m1, [src1q+iq+mmsize]
    movu  [dstq+iq       ], m0
    movu  [dstq+iq+mmsize], m1
    add                 iq, mmsize*2
.end_v:
    cmp                 iq, waq
    jl .loop_v

    ; vector loop
    mov                waq, wq
    and                waq, ~7
    jmp .end_l
.loop_l:
    movq               mm0, [src1q+iq]
    paddb              mm0, [src2q+iq]
    movq  [dstq+iq       ], mm0
    add                 iq, 8
.end_l:
    cmp                 iq, waq
    jl .loop_l

    ; scalar loop for leftover
    jmp .end_s
.loop_s:
    mov                wab, [src1q+iq]
    add                wab, [src2q+iq]
    mov          [dstq+iq], wab
    inc                 iq
.end_s:
    cmp                 iq, wq
    jl .loop_s
    RET
