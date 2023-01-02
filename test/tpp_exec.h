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

/* TPP Includes a builtin `#pragma tpp_exec("foo")' that can be used
 * to run preprocessor text whilst discarding all produced output.
 *
 * Using this, macros are able to (re-)define other macros, or even
 * themselves! */


/* Use __pragma(tpp_exec()) to delete a macro while it's being expanded.
 * This used to fail due to a problem relating to recursive parenthesis
 * tracking failing to skip the trailing `)' in `__pragma(tpp_exec(...))' */
#define foo(x) x
TEST_EXPANDS(foo(10 __pragma(tpp_exec("#undef foo")) 20), "10  20")
TEST_EXPANDS(foo(10 __pragma(tpp_exec("#undef foo")) 20), "foo(10  20)")
TEST_EXPANDS(foo(10 __pragma(tpp_exec("#undef foo")) 20), "foo(10  20)")
TEST_EXPANDS(foo(10 __pragma(tpp_exec("#undef foo")) 20), "foo(10  20)")

#define foo(x) x
TEST_EXPANDS(foo(10 _Pragma("tpp_exec(\"#undef foo\")") 20), "10  20")
TEST_EXPANDS(foo(10 _Pragma("tpp_exec(\"#undef foo\")") 20), "foo(10  20)")
TEST_EXPANDS(foo(10 _Pragma("tpp_exec(\"#undef foo\")") 20), "foo(10  20)")
TEST_EXPANDS(foo(10 _Pragma("tpp_exec(\"#undef foo\")") 20), "foo(10  20)")


#define HACK_COUNTER_VALUE 0
#define STR2(x) #x
#define STR(x) STR2(x)
#define HACK_COUNTER  \
	HACK_COUNTER_VALUE \
	__pragma(tpp_exec( \
	"#undef HACK_COUNTER_VALUE\n" \
	"#define HACK_COUNTER_VALUE " STR(__TPP_EVAL(HACK_COUNTER_VALUE + 1)) "\n" \
	))

TEST_EXPANDS(HACK_COUNTER_VALUE, "0")
TEST_EXPANDS(HACK_COUNTER_VALUE, "0")
TEST_EXPANDS(HACK_COUNTER, "0")
TEST_EXPANDS(HACK_COUNTER, "1")
TEST_EXPANDS(HACK_COUNTER, "2")
TEST_EXPANDS(HACK_COUNTER, "3")
TEST_EXPANDS(HACK_COUNTER_VALUE, "4")

/* When `HACK_COUNTER' isn't actually expanded, then the tpp_exec
 * code must't get executed (since it's skipped in its entirety).
 * Assert this fact! */
#define HIDE(x)
HIDE(HACK_COUNTER)
HIDE(HACK_COUNTER)
HIDE(HACK_COUNTER)

TEST_EXPANDS(HACK_COUNTER_VALUE, "4")



