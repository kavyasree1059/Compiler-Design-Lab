%{
#include <stdio.h>
%}

%%

[aAeEiIoOuU]        { printf("%s is a VOWEL\n", yytext); }
[a-zA-Z]            { printf("%s is a CONSONANT\n", yytext); }
[ \t\n]             ;  // Ignore whitespace
.                   { printf("%s is not an alphabet character\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

