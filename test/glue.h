/* Copyright (c) 2017-2023 Griefer@Work                                       *
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
 *    in a product, an acknowledgement (see the following) in the product     *
 *    documentation is required:                                              *
 *    Portions Copyright (c) 2017-2023 Griefer@Work                           *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#include "include/test.h"

#if 0
#define hash_hash # ## #
#else
// NOTE: NON-Standard:
//  - TPP only allows macro function
//    arguments as operands for the ## operator:
//      <lhs> ## <rhs>
//    - <lhs> and <rhs> must both be a keyword (or number, if __TPP_VERSION__ >= 102)
//    - <lhs> or <rhs> must be a macro function argument
#define GLUE(a,b) a ## b
#define hash_hash GLUE(#,#)
#endif
#define mkstr(a) # a
#define in_between(a) mkstr(a)
#define join(c, d) in_between(c hash_hash d)

TEST_EXPANDS(char p[] = join(x, y);, "char p[] = \"x ## y\";")


