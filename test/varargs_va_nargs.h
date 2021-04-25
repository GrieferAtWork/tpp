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

#define nargs(...) __VA_NARGS__

/* __VA_NARGS__ expands to the decimal repr of the # of variadic arguments */
TEST_EXPANDS(nargs(),    "0")
TEST_EXPANDS(nargs( ),   "0")
TEST_EXPANDS(nargs(~),   "1")
TEST_EXPANDS(nargs(,),   "2")
TEST_EXPANDS(nargs(a,),  "2")
TEST_EXPANDS(nargs(a,b), "2")


/* Using __VA_NARGS__, you can _very_ easily overload macros by argument count! */
#define myfunc_0()     no arguments
#define myfunc_1(a)    first argument is <a>
#define myfunc_2(a, b) first argument: <a>; and second is <b>
#define myfunc(...)    myfunc_##__VA_NARGS__(__VA_ARGS__)

TEST_EXPANDS(myfunc(),                  "no arguments")
TEST_EXPANDS(myfunc( ),                 "no arguments")
TEST_EXPANDS(myfunc("Hello"),           "first argument is <\"Hello\">")
TEST_EXPANDS(myfunc("Hello", "World"),  "first argument: <\"Hello\">; and second is <\"World\">")

#define nargs1(a, ...) a __VA_NARGS__
TEST_EXPANDS(nargs1(),    "0")
TEST_EXPANDS(nargs1( ),   "0")
TEST_EXPANDS(nargs1(~),   "~ 0")
TEST_EXPANDS(nargs1(,),   "0")
TEST_EXPANDS(nargs1(, ),  "0")
TEST_EXPANDS(nargs1(a,),  "a 0")
TEST_EXPANDS(nargs1(a,b), "a 1")

