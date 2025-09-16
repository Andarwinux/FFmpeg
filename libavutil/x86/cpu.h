/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVUTIL_X86_CPU_H
#define AVUTIL_X86_CPU_H

#include "libavutil/cpu.h"
#include "libavutil/cpu_internal.h"

#define X86_MMX(flags)              1
#define X86_MMXEXT(flags)           0
#define X86_SSE(flags)              0
#define X86_SSE2(flags)             1
#define X86_SSE2_FAST(flags)        1
#define X86_SSE2_SLOW(flags)        0
#define X86_SSE3(flags)             1
#define X86_SSE3_FAST(flags)        1
#define X86_SSE3_SLOW(flags)        1
#define X86_SSSE3(flags)            1
#define X86_SSSE3_FAST(flags)       1
#define X86_SSSE3_SLOW(flags)       0
#define X86_SSE4(flags)             1
#define X86_SSE42(flags)            1
#define X86_AVX(flags)              1
#define X86_AVX_FAST(flags)         1
#define X86_AVX_SLOW(flags)         0
#define X86_XOP(flags)              0
#define X86_FMA3(flags)             1
#define X86_FMA4(flags)             0
#define X86_AVX2(flags)             1
#define X86_AESNI(flags)            1
#define X86_CLMUL(flags)            1
#ifdef __AVX512F__
#define X86_AVX512(flags)           1
#else
#define X86_AVX512(flags)           0
#endif

#define EXTERNAL_MMX(flags)         0
#define EXTERNAL_MMXEXT(flags)      0
#define EXTERNAL_SSE(flags)         0
#define EXTERNAL_SSE2(flags)        1
#define EXTERNAL_SSE2_FAST(flags)   1
#define EXTERNAL_SSE2_SLOW(flags)   0
#define EXTERNAL_SSE3(flags)        1
#define EXTERNAL_SSE3_FAST(flags)   1
#define EXTERNAL_SSE3_SLOW(flags)   0
#define EXTERNAL_SSSE3(flags)       1
#define EXTERNAL_SSSE3_FAST(flags)  1
#define EXTERNAL_SSSE3_SLOW(flags)  0
#define EXTERNAL_SSE4(flags)        1
#define EXTERNAL_SSE42(flags)       1
#define EXTERNAL_AVX(flags)         1
#define EXTERNAL_AVX_FAST(flags)    1
#define EXTERNAL_AVX_SLOW(flags)    0
#define EXTERNAL_XOP(flags)         0
#define EXTERNAL_FMA3(flags)        1
#define EXTERNAL_FMA3_FAST(flags)   1
#define EXTERNAL_FMA3_SLOW(flags)   0
#define EXTERNAL_FMA4(flags)        0
#define EXTERNAL_AVX2(flags)        1
#define EXTERNAL_AVX2_FAST(flags)   1
#define EXTERNAL_AVX2_SLOW(flags)   0
#define EXTERNAL_AESNI(flags)       1
#define EXTERNAL_CLMUL(flags)       1

#ifdef __AVX512F__
#define EXTERNAL_AVX512(flags)      1
#else
#define EXTERNAL_AVX512(flags)      0
#endif

#ifdef __AVX512VBMI2__
#define EXTERNAL_AVX512ICL(flags)   1
#else
#define EXTERNAL_AVX512ICL(flags)   0
#endif

#define INLINE_MMX(flags)           0
#define INLINE_MMXEXT(flags)        0
#define INLINE_SSE(flags)           0
#define INLINE_SSE2(flags)          0
#define INLINE_SSE2_FAST(flags)     0
#define INLINE_SSE2_SLOW(flags)     0
#define INLINE_SSE3(flags)          0
#define INLINE_SSE3_FAST(flags)     0
#define INLINE_SSE3_SLOW(flags)     0
#define INLINE_SSSE3(flags)         0
#define INLINE_SSSE3_FAST(flags)    0
#define INLINE_SSSE3_SLOW(flags)    0
#define INLINE_SSE4(flags)          0
#define INLINE_SSE42(flags)         0
#define INLINE_AVX(flags)           0
#define INLINE_AVX_FAST(flags)      0
#define INLINE_AVX_SLOW(flags)      0
#define INLINE_XOP(flags)           0
#define INLINE_FMA3(flags)          0
#define INLINE_FMA4(flags)          0
#define INLINE_AVX2(flags)          0
#define INLINE_AESNI(flags)         0

void ff_cpu_cpuid(int index, int *eax, int *ebx, int *ecx, int *edx);
void ff_cpu_xgetbv(int op, int *eax, int *edx);
int  ff_cpu_cpuid_test(void);

#endif /* AVUTIL_X86_CPU_H */
