%{
#include <stdio.h>
%}

%%

[0-9]+\.[0-9]+     { printf("%s is a FLOATING POINT number\n", yytext); }
[0-9]+             { printf("%s is an INTEGER\n", yytext); }
[ \t\n]            ; // Ignore whitespace
.                  { printf("%s is not a number\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

