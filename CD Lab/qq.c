#include <stdio.h>
#include <string.h>

int main() {
    char gram[100], part1[100], part2[100], modifiedGram[100], newGram[100];
    int i, j = 0, k = 0, pos = 0;

    printf("Enter Production : A->");
    // Using fgets instead of gets for safety
    fgets(gram, sizeof(gram), stdin);

    // Remove trailing newline from fgets
    gram[strcspn(gram, "\n")] = 0;

    // Split input around '|'
    for (i = 0; gram[i] != '|' && gram[i] != '\0'; i++, j++) {
        part1[j] = gram[i];
    }
    part1[j] = '\0';

    if (gram[i] == '|') {
        i++; // skip '|'
    }
    for (j = 0; gram[i] != '\0'; i++, j++) {
        part2[j] = gram[i];
    }
    part2[j] = '\0';

    // Find common prefix
    for (i = 0; i < strlen(part1) && i < strlen(part2); i++) {
        if (part1[i] == part2[i]) {
            modifiedGram[k] = part1[i];
            k++;
            pos = i + 1;
        } else {
            break;
        }
    }

    modifiedGram[k] = 'X'; // New non-terminal
    modifiedGram[k + 1] = '\0';

    // Store the differing suffixes for new production X
    j = 0;
    for (i = pos; i < strlen(part1); i++, j++) {
        newGram[j] = part1[i];
    }
    newGram[j++] = '|';
    for (i = pos; i < strlen(part2); i++, j++) {
        newGram[j] = part2[i];
    }
    newGram[j] = '\0';

    printf("\nA->%s", modifiedGram);
    printf("\nX->%s\n", newGram);

    return 0;
}

