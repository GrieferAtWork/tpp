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

// Function-style macro calling and argument count

#define arg0()           -
#define arg1(a)          a
#define arg2(a,b)        a##b
#define varg0(...)       __VA_ARGS__
#define varg1(a,...)     a##__VA_ARGS__
#define varg2(a,b,...)   a##b##__VA_ARGS__
#define vcarg0(...)      __VA_COMMA__ __VA_ARGS__ __VA_COMMA__
#define vcarg1(a,...)    __VA_COMMA__ a##__VA_ARGS__ __VA_COMMA__
#define vcarg2(a,b,...)  __VA_COMMA__ a##b##__VA_ARGS__ __VA_COMMA__

// NOTE: Space tokens [ ] are not included in the expansion comments
TEST_EXPANDS(arg0(),"-")            // OK

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(arg0(a),"-")           // WARNING: Invalid argument count (expected 0)
PRAGMA_WARNING_POP_SUPPRESS("macros")

TEST_EXPANDS(arg1(),"")             // OK
TEST_EXPANDS(arg1(a),"a")           // OK
PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(arg1(a,b),"a,b")       // WARNING: Invalid argument count (expected 1)
PRAGMA_WARNING_POP_SUPPRESS("macros")

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(arg1(,),",")           // WARNING: Invalid argument count (expected 1)
PRAGMA_WARNING_POP_SUPPRESS("macros")

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(arg2(a),"a")           // WARNING: Invalid argument count (expected 2)
PRAGMA_WARNING_POP_SUPPRESS("macros")

TEST_EXPANDS(arg2(a,),"a")          // OK
TEST_EXPANDS(arg2(,),"")            // OK
TEST_EXPANDS(arg2(a,b),"ab")        // OK

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(arg2(,,),",")          // WARNING: Invalid argument count (expected 2)
PRAGMA_WARNING_POP_SUPPRESS("macros")

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(arg2(a,b,c),"ab,c")    // WARNING: Invalid argument count (expected 2)
PRAGMA_WARNING_POP_SUPPRESS("macros")

TEST_EXPANDS(varg0(),"")            // OK
TEST_EXPANDS(varg0(a),"a")          // OK
TEST_EXPANDS(varg0(a,),"a,")        // OK
TEST_EXPANDS(varg0(,),",")          // OK
TEST_EXPANDS(varg0(a,b),"a,b")      // OK
TEST_EXPANDS(vcarg0(),"")           // OK
TEST_EXPANDS(vcarg0(a),", a ,")     // OK
TEST_EXPANDS(vcarg0(a,),", a, ,")   // OK
TEST_EXPANDS(vcarg0(,),", , ,")     // OK
TEST_EXPANDS(vcarg0(a,b),", a,b ,") // OK
TEST_EXPANDS(varg1(),"")            // OK
TEST_EXPANDS(varg1(a),"a")          // OK
TEST_EXPANDS(varg1(a,),"a")         // OK
TEST_EXPANDS(varg1(,),"")           // OK
TEST_EXPANDS(varg1(a,b),"ab")       // OK
TEST_EXPANDS(vcarg1(),"")           // OK
TEST_EXPANDS(vcarg1(a),"a")         // OK
TEST_EXPANDS(vcarg1(a,),"a")        // OK
TEST_EXPANDS(vcarg1(,),"")          // OK
TEST_EXPANDS(vcarg1(a,b),", ab ,")  // OK

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(varg2(a),"a")          // WARNING: Invalid argument count (expected >= 2)
PRAGMA_WARNING_POP_SUPPRESS("macros")

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(varg2(),"")            // WARNING: Invalid argument count (expected >= 2)
PRAGMA_WARNING_POP_SUPPRESS("macros")

TEST_EXPANDS(varg2(a,),"a")         // OK
TEST_EXPANDS(varg2(,),"")           // OK
TEST_EXPANDS(varg2(a,b),"ab")       // OK

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(vcarg2(),"")           // WARNING: Invalid argument count (expected >= 2)
PRAGMA_WARNING_POP_SUPPRESS("macros")

PRAGMA_WARNING_PUSH_SUPPRESS("macros")
TEST_EXPANDS(vcarg2(a),"a")         // WARNING: Invalid argument count (expected >= 2)
PRAGMA_WARNING_POP_SUPPRESS("macros")

TEST_EXPANDS(vcarg2(a,),"a")        // OK
TEST_EXPANDS(vcarg2(,),"")          // OK
TEST_EXPANDS(vcarg2(a,b),"ab")      // OK

