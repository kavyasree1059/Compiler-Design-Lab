#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[50], stack[50];



char m[5][6][5] = {
    {"tb",  "",   "",   "tb", "",  ""},     
    {"",   "+tb", "",   "",   "n", "n"},   
    {"fc",  "",   "",   "fc", "",  ""},     
    {"",    "n",  "*fc","",   "n", "n"},    
    {"i",   "",   "",   "(e)", "",  ""}    
};

int size[5][6] = {
    {2, 0, 0, 2, 0, 0},  // e
    {0, 3, 0, 0, 1, 1},  // b
    {2, 0, 0, 2, 0, 0},  // t
    {0, 1, 3, 0, 1, 1},  // c
    {1, 0, 0, 3, 0, 0}   // f
};

int main() {
    int top = 1; 
    int i = top, j = 0, k;
    int row, col;

    printf("Enter the input string: ");
    scanf("%s", input);
    strcat(input, "$");

    int len = strlen(input);

    stack[0] = '$';
    stack[1] = 'e';

    printf("\nStack\t\tInput\n");
    printf("------------------------\n");

    while (stack[i] != '$' || input[j] != '$') {
     
        for (k = 0; k <= i; k++) printf("%c", stack[k]);
        printf("\t\t");
        
        for (k = j; k < len; k++) printf("%c", input[k]);
        printf("\n");

        if (stack[i] == input[j]) {
            
            i--;
            j++;
        }
        else {
          
            switch(stack[i]) {
                case 'e': row = 0; break;
                case 'b': row = 1; break;
                case 't': row = 2; break;
                case 'c': row = 3; break;
                case 'f': row = 4; break;
                default:
                    printf("\nERROR: Invalid symbol '%c' on stack\n", stack[i]);
                    exit(0);
            }

            switch(input[j]) {
                case 'i': col = 0; break;
                case '+': col = 1; break;
                case '*': col = 2; break;
                case '(': col = 3; break;
                case ')': col = 4; break;
                case '$': col = 5; break;
                default:
                    printf("\nERROR: Invalid input symbol '%c'\n", input[j]);
                    exit(0);
            }

            if (m[row][col][0] == '\0') {
                printf("\nERROR: No rule for %c on input %c\n", stack[i], input[j]);
                exit(0);
            }
            else if (m[row][col][0] == 'n') {
               
                i--;
            }
            else {
              
                i--;
               
                for (k = size[row][col] - 1; k >= 0; k--) {
                    stack[++i] = m[row][col][k];
                }
            }
        }
    }

    printf("\nSUCCESS: String parsed successfully!\n");

    return 0;
}

