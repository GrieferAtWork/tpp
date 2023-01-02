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

// ISO/IEC 9899:201x - 6.10.3 - 5 + 6

// ISO/IEC 9899:201x - 6.10.3 - 5
PRAGMA_WARNING_PUSH_SUPPRESS("macros")
#define VARARGS(__VA_ARGS__) __VA_ARGS__ /* Warning: __VA_ARGS__ used as argument name */
PRAGMA_WARNING_POP_SUPPRESS("macros")
TEST_EXPANDS(VARARGS(foo), "foo")
#undef VARARGS

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
#define VARARGS(__VA_COMMA__) __VA_COMMA__ /* Warning: __VA_COMMA__ used as argument name */
PRAGMA_WARNING_POP_SUPPRESS("macros")
TEST_EXPANDS(VARARGS(foo), "foo")
#undef VARARGS

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
#define VARARGS(__VA_OPT__) __VA_OPT__ /* Warning: __VA_OPT__ used as argument name */
PRAGMA_WARNING_POP_SUPPRESS("macros")
TEST_EXPANDS(VARARGS(foo), "foo")
#undef VARARGS

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
#define VARARGS(__VA_NARGS__) __VA_NARGS__ /* Warning: __VA_NARGS__ used as argument name */
PRAGMA_WARNING_POP_SUPPRESS("macros")
TEST_EXPANDS(VARARGS(foo), "foo")
#undef VARARGS

// ISO/IEC 9899:201x - 6.10.3 - 6
PRAGMA_WARNING_PUSH_SUPPRESS("macros")
#define ARG_NAMES(a,b,c,a) a+b+c+a /* Warning: Parameter name "a" reused */
PRAGMA_WARNING_POP_SUPPRESS("macros")
TEST_EXPANDS(ARG_NAMES(10,20,30), "10+20+30+10")



