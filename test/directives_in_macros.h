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

/* Preprocessor blocks within macro arguments */

TEST_EXPANDS(
#if 0
	Stuff in the middle
#endif
, "")

TEST_EXPANDS(
#if 1
	Stuff in the middle
#endif
, "Stuff in the middle")

#define NARGS(...) __VA_NARGS__

TEST_EXPANDS(NARGS(
#if 0
	a
#endif
), "1")

TEST_EXPANDS(NARGS(
#if 0
	a
#endif
	b
), "1")

TEST_EXPANDS(NARGS(
	b
#if 0
	a
#endif
), "1")

TEST_EXPANDS(NARGS(
#if 1
	a
#endif
), "1")

#define EAT(...) __pragma(tpp_exec(#__VA_ARGS__))
#define EXPAND_HIDDEN(a, b) EAT(a, b)

PRAGMA_WARNING_PUSH_SUPPRESS("syntax")
EXPAND_HIDDEN(
	a
#if 0      /* E0032("-Wsyntax"): #if without #endif */
	,
PRAGMA_WARNING_POP_SUPPRESS("syntax")
PRAGMA_WARNING_PUSH_SUPPRESS("syntax") /* Supress again for 2nd syntax error */
#endif     /* E0033("-Wsyntax"): #endif without #if */
	b
)
PRAGMA_WARNING_POP_SUPPRESS("syntax")




