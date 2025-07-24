%{
#include <stdio.h>
%}

%%

"int" |
"float" |
"return" |
"if" |
"else" |
"while" |
"for"               { printf("%s is a C keyword\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* { printf("%s is an identifier\n", yytext); }

[ \t\n]             ; // Ignore spaces

.                   { printf("%s is something else\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

