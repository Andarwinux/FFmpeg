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

#ifndef AVUTIL_AARCH64_CPU_H
#define AVUTIL_AARCH64_CPU_H

#include "libavutil/cpu.h"
#include "libavutil/cpu_internal.h"

#define have_armv8(flags)   1
#define have_neon(flags)    1
#define have_vfp(flags)     1
#define have_arm_crc(flags) 1

#if defined(__ARM_FEATURE_DOTPROD)
#define have_dotprod(flags) 1
#else
#define have_dotprod(flags) CPUEXT(flags, DOTPROD)
#endif

#if defined(__ARM_FEATURE_MATMUL_INT8)
#define have_i8mm(flags)    1
#else
#define have_i8mm(flags)    CPUEXT(flags, I8MM)
#endif

#if defined(__ARM_FEATURE_SVE)
#define have_sve(flags)     1
#else
#define have_sve(flags)     CPUEXT(flags, SVE)
#endif

#if defined(__ARM_FEATURE_SVE2)
#define have_sve2(flags)    1
#else
#define have_sve2(flags)    CPUEXT(flags, SVE2)
#endif

#if defined(__ARM_FEATURE_SME)
#define have_sme(flags)     1
#else
#define have_sme(flags)     CPUEXT(flags, SME)
#endif

#if HAVE_SVE
int ff_aarch64_sve_length(void);
#endif

#if HAVE_SME
int ff_aarch64_sme_length(void);
#endif

#endif /* AVUTIL_AARCH64_CPU_H */
