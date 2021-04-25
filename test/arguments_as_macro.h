/* Copyright (c) 2018-2021 Griefer@Work                                       *
 *                                                                            *
 * This software is provided 'as-is', without any express or implied          *
 * warranty. In no event will the authors be held liable for any damages      *
 * arising from the use of this software.                                     *
 *                                                                            *
 * Permission is granted to anyone to use this software for any purpose,      *
 * including commercial applications, and to alter it and redistribute it     *
 * freely, subject to the following restrictions:                             *
 *                                                                            *
 * 1. The origin of this software must not be misrepresented; you must not    *
 *    claim that you wrote the original software. If you use this software    *
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#include "include/test.h"

#define args 10,20,30
#define func(a,b,c) a+b+c

#pragma warning("-Wmacros")
#if !__has_warning("-Wmacros")
#error "Should now be enabled"
#endif
#pragma warning("-Wsup-macros")
#if __has_warning("-Wmacros")
#error "Should now be suppressed (once)"
#endif

/* E0105("-Wmacros"): Not enough enough arguments for `func' */
/* NOTE: Expands to:
 *  >> [func][(][args][)]
 *  >> [args][+][][+][]
 *  >> [10][,][20][,][30][+][+] */
TEST_EXPANDS(func(args), "10,20,30++")

#if !__has_warning("-Wmacros")
#error "Should have been triggered"
#endif

