#include<stdio.h>
#include<string.h>

int main() {
    char gram[20], part1[20], part2[20], modifiedGram[20], newGram[20];
    int i, j = 0, k = 0, l = 0, pos;

    // Input grammar from the user
    printf("Enter Production : A->");
    // Use fgets() instead of gets()
    fgets(gram, sizeof(gram), stdin);
    
    // Remove the newline character left by fgets()
    gram[strcspn(gram, "\n")] = '\0';

    // Split the grammar into two parts based on the '|'
    for(i = 0; gram[i] != '|'; i++, j++) 
        part1[j] = gram[i];
    part1[j] = '\0'; // End of part1

    for(j = ++i, i = 0; gram[j] != '\0'; j++, i++) 
        part2[i] = gram[j];
    part2[i] = '\0'; // End of part2

    // Find the common part between part1 and part2
    for(i = 0; i < strlen(part1) || i < strlen(part2); i++) {
        if(part1[i] == part2[i]) {
            modifiedGram[k] = part1[i];
            k++;
            pos = i + 1; // Point of divergence
        }
    }

    // Create the new grammar with factored part
    for(i = pos, j = 0; part1[i] != '\0'; i++, j++) {
        newGram[j] = part1[i];
    }
    newGram[j++] = '|'; // Add separator for the alternatives
    for(i = pos; part2[i] != '\0'; i++, j++) {
        newGram[j] = part2[i];
    }

    // Add the non-terminal X
    modifiedGram[k] = 'X';
    modifiedGram[++k] = '\0';
    newGram[j] = '\0'; // End of new grammar

    // Output the modified grammar
    printf("\n A->%s", modifiedGram);
    printf("\n X->%s\n", newGram);

    return 0;
}
