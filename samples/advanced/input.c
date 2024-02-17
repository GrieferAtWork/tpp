
#pragma message "It's working!"

#define foo(a, b) a+b+a+b

printf("x = %d", foo(10, MY_MACRO) == __TPP_EVAL(foo(10, MY_MACRO)));
#ifdef __MY_PREDEFINED_MACRO__
IS PREDEFINED
#endif
#if __has_extension("-fawesome")
awesome
#endif

#if __is_builtin_identifier(async)
Its-a-builtin!
#endif

#if __is_builtin_identifier(not_async)
#error "This one wasn't defined in 'my-custom-tpp-defs.h', so it shouldn't be a builtin"
#endif

/*Expected output (token IDs may differ):

It's working!
input.c:6:1: 814: 'printf'
input.c:6:7: 40: '('
input.c:6:8: 34: '"x = %d"'
input.c:6:16: 44: ','
input.c:6:35: 48: '10' [in macro 'foo' at input.c:4:19]
input.c:6:35: 43: '+' [in macro 'foo' at input.c:4:20]
input.c:6:35: 48: '42' [in macro 'foo' at input.c:4:21]
input.c:6:35: 43: '+' [in macro 'foo' at input.c:4:22]
input.c:6:35: 48: '10' [in macro 'foo' at input.c:4:23]
input.c:6:35: 43: '+' [in macro 'foo' at input.c:4:24]
input.c:6:35: 48: '42' [in macro 'foo' at input.c:4:25]
input.c:6:36: 258: '=='
input.c:6:68: 48: '104'
input.c:6:68: 41: ')'
input.c:6:69: 59: ';'
input.c:8:1: 815: 'IS'
input.c:8:4: 816: 'PREDEFINED'
input.c:11:1: 817: 'awesome'
input.c:15:1: 818: 'Its'
input.c:15:4: 45: '-'
input.c:15:5: 812: 'a'
input.c:15:6: 45: '-'
input.c:15:7: 819: 'builtin'
input.c:15:14: 33: '!'

*/
