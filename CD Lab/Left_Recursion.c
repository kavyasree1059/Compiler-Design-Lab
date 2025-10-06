#include<stdio.h>
#include<string.h>
#define SIZE 10

int main() {
    char non_terminal, beta, alpha;
    int num;
    char production[10][SIZE];
    int index = 3; // Index of the string after "->"

    printf("Enter Number of Productions: ");
    scanf("%d", &num);
    printf("Enter the grammar as E->E-A:\n");

    // Input the productions
    for(int i = 0; i < num; i++) {
        scanf("%s", production[i]);
    }

    // Check each production for left recursion
    for(int i = 0; i < num; i++) {
        printf("\nGRAMMAR : : : %s", production[i]);
        non_terminal = production[i][0]; // Get the non-terminal

        // Check if the production has left recursion
        if(non_terminal == production[i][index]) {
            alpha = production[i][index+1];
            printf(" is left recursive.\n");

            // Find the beta part after the recursive part
            while(production[i][index] != 0 && production[i][index] != '|')
                index++;

            if(production[i][index] != 0) {
                beta = production[i][index+1];
                printf("Grammar without left recursion:\n");
                printf("%c->%c%c\'", non_terminal, beta, non_terminal);
                printf("\n%c\'->%c%c\'|E\n", non_terminal, alpha, non_terminal);
            } else {
                printf(" can't be reduced\n");
            }
        } else {
            printf(" is not left recursive.\n");
        }
        index = 3; // Reset index for next production
    }

    return 0;
}
