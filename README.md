# tpp - Tiny PreProcessor

TPP is a tiny (single source file) C Preprocessor, meant as a low-level backend for compilers of C and C-like languages, whilst implementing pretty much all preprocessor extensions supported by other compilers, ontop of a large number of its own (tpp-specific) extensions.

### Usage

TPP is designed to be used in 1 of 2 ways:

- As a back-end for writing C and C-like compilers with all of the work needed for dealing with macros, directives, warnings, and preprocessor-related pragmas already taken care of.  
  For this purpose, TPP is meant to be included statically as part of another project's source tree.
  - For samples on how this can be done, look in `/samples`

- As a standalone Preprocessor (similar to GNU's `cpp` utility).  
  For this purpose, you may build `src/frontend.c` to produce the commandline utility


### Features

- TPP operates without any intermediate buffers, in that it is capable of preprocessing/tokenizing text in real-time from stream-like input sources:

  ```sh
  cat file.c | tpp
  ```

  The above command can be used to preprocess text, without any need for any intermediate buffers (beyond what is needed for a single token) before TPP will start producing output.

  This means that TPP will be able to parse input, and print preprocessed output in real-time, without needing to wait for you to close a PIPE, or reach the end of its input file, first.

  In a sense, this can be compared to python's interactive commandline, which allows it to execute code as you write it. So while an interactive C commandline ~~is probably impossible~~ [is possible](https://github.com/GrieferAtWork/dcc), an interactive C preprocessor ~~most definitely isn't~~ obviously is, too. - Because that's what TPP is.

- Invocation of the TPP frontend is also designed to be usable by other utilities via the `--pp` switch, which, rather than producing preprocessed output, will emit individual tokens seperated by `'\0'`-characters, allowing you to leave all of the tokenization to tpp, and do the processing yourself in a seperate process.


### Preprocessor Extensions

All extensions can be hard enabled/disabled when building tpp, or soft-enabled/disabled via `#pragma extension("-fname")` / `#pragma extension("-fno-name")` directives.

Supported extensions can be tested for with `__has_known_extension("name")`, and supported+enabled extensions with `__has_extension("name")`. In turn, `__has_known_extension` and `__has_extension` can be tested for with `#ifdef`.

- Trigraphs (`??*`)
- Digraphs (`<%` is `{`, etc...)
- STDC `__VA_ARGS__` (`#define printf(...) fprintf(stderr, __VA_ARGS__)`)
- GCC-style varargs macros (`#define printf(format...) fprintf(stderr, format)`)
- GCC-style va-comma (`#define printf(format, ...) fprintf(stderr, format, ##__VA_ARGS__)`)
- GCC-style if-else in expressions (`#if foo ?: bar`; same as `#if foo ? foo : bar`)
- c++20 `__VA_OPT__` (`#define printf(format, ...) fprintf(stderr, format __VA_OPT__(,) __VA_ARGS__)`)
- `'\e'` escape codes in strings and characters (for ASCII `ESC`, iow: `'\x1b'`)
- Binary literals (`0b00101010`)
- MSVC's `__pragma(foo)` built-in function-like directive/macro
- STDC's `_Pragma("foo")` built-in function-like directive/macro
- GCC-style `#warning My Message Here` directives
- GCC-style `#include_next <header.h>` directives
- OBJc-style `#import <header.h>` directives
- `#ident` and `#sccs` directives (true origin unknown; accepted by some ancient compilers for placing comments into `.o`-files)
- STDC magic macros `__FILE__`, `__LINE__`, `__TIME__` and `__DATE__`
- Magic macro `__BASE_FILE__`
- Magic macros `__INCLUDE_LEVEL__` and `__INCLUDE_DEPTH__`
- Magic macro `__COUNTER__`
- Magic macro `__TIMESTAMP__`
- Magic macro `__COLUMN__` (tpp-specific; like `__LINE__`, but the current column-position)
- STDC-compliant preprocessor `#if`-expressions
- All STDC-required preprocessor directives (`#define`, `#undef`, `#if`, `#ifdef`, `#ifndef`, `#elif`, `#else`, `#endif`, `#include`, `#pragma`, `#error`)
- Clang-style feature test macros:
	- `__has_include()`
	- `__has_include_next()`
	- `__is_identifier()`, `__is_deprecated()`, `__is_poisoned()`
	- `__has_attribute()`, `__has_builtin()`, ...
	- `__is_builtin_identifier()` (tpp-specific)
	- `__has_extension()`, `__has_known_extension()` (tpp-specific)
	- `__has_warning()`, `__has_known_warning()` (tpp-specific)
- Treat `#!`-directives as comments (i.e. `#!/bin/tpp` is treated as a comment)
- Treat `$` as a character, which may thus appear in an identifier
- Preprocessor assertions (no; not those from `<assert.h>`..., but this):
	- `#assert cpu(mycpu)`
	- `#unassert cpu(yourcpu)`
	- `#if #cpu(mycpu)`
- Multi-char character literals (e.g. `#if 'abc' == 6513249`)
- `__VA_COMMA__` (tpp-specific extension)
	- `#define printf(format, ...) fprintf(stderr, format __VA_COMMA__ __VA_ARGS__)`
	- Expands to `,` when `__VA_ARGS__` are non-empty and `/**/` when empty.
	- Essentially the same as `__VA_OPT__(,)`
- `__VA_NARGS__` (tpp-specific extension)
	- Expands to the decimal representation of the # of arguments in `__VA_ARGS__`
	- Useful for overloading macros by argument count  

	  ```c
	  #define min_1(a)       a
	  #define min_2(a, b)    ((a) < (b) ? (a) : (b))
	  #define min_3(a, b, c) min_2(min_2(a, b), c)
	  #define min(...)       min_##__VA_NARGS__(__VA_ARGS__)
	  ```
- Optional support for traditional macro expansion rules (disabled by default, can be enabled temporarily via `#pragma extension`)
	- ```c
	  #define CAT(a,b) a ## b
	  #define STR(x)   #x
	  #pragma extension(push, "-ftraditional-macro")
	  #define T_CAT(a, b) a/**/b
	  #define T_STR(x)    "x"
	  #pragma extension(pop)
	  CAT(10, 20)   // 1020
	  STR(10)       // "10"
	  T_CAT(10, 20) // 1020
	  T_STR(10)     // "10"
	  ```
	- Test for with `#if __has_known_extension("traditional-macro")`
- Alternative parenthesis for macro definitions (tpp-specific extension):
	- Allow use of:
		- `#define foo(a,b) ...`
		- `#define foo[a,b] ...`
		- `#define foo{a,b} ...`
		- `#define foo<a,b> ...`
	- In other words: define macros that use tokens other than `(...)`-pairs for arguments
	- Test for with `#if __has_extension("alternative-macro-parenthesis")`
- Self-recursive macros (tpp-specific extension):
	- STDC specifies that macros that try to expand to themselves should not be allowed to do so when this happens
	- TPP has an optional extension to relax this rule for function-like macros defined while this extension is active
	- Such function-like macros are allowed to expand to themselves, so-long as arguments passed during expansion differ from all other invocations of the same macro along the macro-expansion call-stack
	- Test for with `#if __has_known_extension("macro-recursion")`
	- Enable/disable with `#pragma extension("-fmacro-recursion")` and `#pragma extension("-fno-macro-recursion")`
- Whitespace-sensitivity (tpp-specific extension):
	- STDC specifies that whitespace should be stripped around macro bodies. - However, some programming languages are whitespace sensitive, meaning that the removal of whitespace in such cincumstances may alter program behavior.
	- For this purpose, TPP has an option to keep whitespace if necessary.
	- Test for with `#if __has_extension("macro-argument-whitespace")`
- Allow select operations on string literals in preprocessor expressions (tpp-specific extension):
	- `#if "FOO" != "BAR"`
	- `#if "FOO"[0] == 'F'`
	- `#if "FOO"[1:] == "OO"`
	- `#if #"FOO" == 3`
	- Test for with `#if __has_extension("strings-in-expressions")`
- Allow for GCC-style `__builtin_*` function calls in preprocessor expressions (tpp-specific extension):
	- `#if __builtin_ffs(0x100) == 9`
	- Test for with `#if __has_extension("builtins-in-expressions")`
- Allow for `#@` as a replacement for `#` to convert macro arguments into character literals, rather than strings:
	- ```c
	  #define STR(x) #x
	  #define CHR(x) #@x
	  STR(f) // "f"
	  CHR(f) // 'f'
	  ```
	- Test for with `#if __has_extension("charize-macro-argument")`
- Prevent in-place expansion of macro arguments during macro-function-expansion (tpp-specific extension) (s.a. `/test/pound_xclaim.h`)
	- Test for with `#if __has_extension("dont-expand-macro-argument")`
- Logical Xor operators (`A ^^ B`; same as `!!(A) ^ !!(B)`) (tpp-specific extension)
- Precise date/time macros (tpp-specific extension):
	- `__DATE_DAY__`, `__DATE_WDAY__`, `__DATE_YDAY__`, `__DATE_MONTH__`, `__DATE_YEAR__`
	- `__TIME_SEC__`, `__TIME_MIN__`, `__TIME_HOUR__`
	- Test for with `#ifdef <macro-name>`
- Evaluate preprocessor expressions, and expand to their decimal/string representation (tpp-specific extension):
	- For example: `__TPP_EVAL(10 + 20)` would expand to exactly 1 token `30`
	- Highly useful because you can do stuff like:

	  ```c
	  #define CAT2(a, b) a##b
	  #define CAT(a, b) CAT2(a, b)
	  #define ISLESS_0 more than
	  #define ISLESS_1 less than
	  #define SELECT(n) CAT(ISLESS_, __TPP_EVAL(n < 10))
	  SELECT(7)  // Expands to `less than'
	  SELECT(10) // Expands to `more than'
	  ```
	- Can also be combined with `"strings-in-expressions"` to operate on strings:

	  ```c
	  __TPP_EVAL("foobar"[3:]) // Expands to "bar"
	  ```
	- Test for with `#ifdef __TPP_EVAL`
- Generate unique IDs for a given keyword/name (that remain unchanged when re-compiling the same file without altering its contents) (tpp-specific extension):
	- For example, `__TPP_UNIQUE(foo)` expands to a unique decimal integer that will remain the same for `foo` within the entire input (though not necessarily within other files that may be preprocessed seperately)
	- Test for with `#ifdef __TPP_UNIQUE`
- Load the contents of a #include-file into a string (tpp-specific extension):
	- For example, `__TPP_LOAD_FILE("file.c")` will expand to the the contents of `file.c`, contained in, and escaped as a `"string"`
	- Test for with `#ifdef __TPP_LOAD_FILE`
- An arbitrary number of `__COUNTER__`-like counters (tpp-specific extension):
	- For example, each time `__TPP_COUNTER(foo)` is encountered, it will expand to 1 greater than its previous expansion (starting at `0`)
	- Similar behavior is also possible with `__COUNTER__`, however using `__TPP_COUNTER`, you can have an arbitrary number of counters operating independent of each other.
	- Test for with `#ifdef __TPP_COUNTER`
- Random number generation (tpp-specific extension):
	- Generate a random number in `[0,hi)` with `__TPP_RANDOM(hi)`
	- Generate a random number in `[lo,hi)` with `__TPP_RANDOM(lo, hi)`
	- Test for with `#ifdef __TPP_RANDOM`
- Re-interprete the contents of a string token as input text (tpp-specific extension):
	- ```c
	  #define foo 42
	  __TPP_STR_DECOMPILE("foo bar") // Expands to `42 bar'
	  ```
	- Test for with `#ifdef __TPP_STR_DECOMPILE`
- Pack together a string token from the ASCII codes of its individual characters (tpp-specific extension):
	- For example, `__TPP_STR_PACK(0x48, 0x65, 0x6c, 0x6c, 0x6f)` expands to `"Hello"`
	- Test for with `#ifdef __TPP_STR_PACK`
- More extensions exist, but I feel those are not important enough to document here
	- Most notably, supported `#pragma` directives, such as `#pragma once`, `#pragma push_macro()`, etc...
