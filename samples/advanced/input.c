
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
token: 816: 'printf'
token: 40: '('
token: 34: '"x = %d"'
token: 44: ','
token: 48: '10'
token: 43: '+'
token: 48: '42'
token: 43: '+'
token: 48: '10'
token: 43: '+'
token: 48: '42'
token: 258: '=='
token: 48: '104'
token: 41: ')'
token: 59: ';'
token: 817: 'IS'
token: 818: 'PREDEFINED'
token: 819: 'awesome'
token: 820: 'Its'
token: 45: '-'
token: 814: 'a'
token: 45: '-'
token: 821: 'builtin'
token: 33: '!'

*/
