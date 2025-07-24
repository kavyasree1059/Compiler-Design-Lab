%{
#include <stdio.h>
%}
%%

"==" |
"!=" |
"<=" |
">=" |
"<" |
">"                  { printf("%s is a relational operator\n", yytext); }

"+" |
"-" |
"*" |
"/" |
"="                  { printf("%s is an arithmetic/assignment operator\n", yytext); }

[ \t\n]             ; // Ignore spaces

.                   { printf("%s is not an operator\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

