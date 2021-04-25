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

#define TEST_STR2(...) #__VA_ARGS__
#define TEST_STR(...)  TEST_STR2(__VA_ARGS__)
#ifndef __pragma
#define __pragma(...) _Pragma(TEST_STR2(__VA_ARGS__))
#endif /* !__pragma */
#define TEST_PRINT(...) __pragma(message(__VA_ARGS__))

#define _TEST_ASSERT_0(msg)      __pragma(error(__FILE__ "(" TEST_STR(__LINE__) ") : Assertion failed: '" msg "'"))
#define _TEST_ASSERT_1(msg)      /* Success */
#define _TEST_ASSERT2(expr, msg) _TEST_ASSERT_##expr(msg)
#define _TEST_ASSERT(expr, msg)  _TEST_ASSERT2(expr, msg)
#define TEST_ASSERT(expr)        _TEST_ASSERT(__TPP_EVAL(!!(expr)), #expr)

#define TEST_EXPANDS(text, to)                                    \
	TEST_PRINT("\tTesting: expands: " #to)  \
	_TEST_ASSERT(__TPP_EVAL(TEST_STR2(text) == to), "\n\tWanted: " #to "\n\tGot:    " TEST_STR(TEST_STR2(text)))

#define PRAGMA_WARNING_PUSH_SUPPRESS(name) \
	__pragma(warning(push, "-W" name))     \
	TEST_ASSERT(__has_warning("-W" name))  \
	__pragma(warning("-Wsup-" name))       \
	TEST_ASSERT(!__has_warning("-W" name))
#define PRAGMA_WARNING_POP_SUPPRESS(name)  \
	TEST_ASSERT(__has_warning("-W" name))  \
	__pragma(warning(pop))



