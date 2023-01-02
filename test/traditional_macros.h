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

#define CAT(a,b) a ## b
#define STR(x)   #x

/* Enabling "-ftraditional-macro" alters macro definitions
 * to follow more ~traditional~ expansion rules. */
#pragma extension(push, "-ftraditional-macro")
#define T_CAT(a, b) a/**/b
#define T_STR(x)    "x"
#pragma extension(pop)

#define N_CAT(a, b) a/**/b
#define N_STR(x)    "x"

TEST_EXPANDS(CAT(10, 20),   "1020")
TEST_EXPANDS(STR(10),       "\"10\"")
TEST_EXPANDS(T_CAT(10, 20), "1020")
TEST_EXPANDS(T_STR(10),     "\"10\"")
TEST_EXPANDS(N_CAT(10, 20), "10/**/20")
TEST_EXPANDS(N_STR(10),     "\"x\"")
