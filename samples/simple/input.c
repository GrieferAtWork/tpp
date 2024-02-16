
#pragma message "It's working!"

#define foo(a, b) a+b+a+b

printf("x = %d", foo(10, MY_MACRO) == __TPP_EVAL(foo(10, MY_MACRO)));

/*Expected output (token IDs may differ):

It's working!
token: 806: 'printf'
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

*/
