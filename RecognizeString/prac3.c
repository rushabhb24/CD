#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[20], c;
    int state = 0, i = 0;

    // Prompt for input and use fgets instead of gets to prevent overflow
    printf("\nEnter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove the newline character at the end of the string, if present
    s[strcspn(s, "\n")] = 0;

    // Loop through the input string and process it
    while (s[i] != '\0') {
        c = s[i++];
        switch (state) {
            case 0:
                if (c == 'a') {
                    state = 1;
                } else if (c == 'b') {
                    state = 2;
                } else {
                    state = 6;  // Invalid character for this state
                }
                break;

            case 1:
                if (c == 'a') {
                    state = 3;
                } else if (c == 'b') {
                    state = 4;
                } else {
                    state = 6;  // Invalid character for this state
                }
                break;

            case 2:
                if (c == 'a') {
                    state = 6;  // Invalid transition for 'a'
                } else if (c == 'b') {
                    state = 2;  // Stay in state 2 if 'b' encountered
                } else {
                    state = 6;  // Invalid character for this state
                }
                break;

            case 3:
                if (c == 'a') {
                    state = 3;  // Stay in state 3 if 'a' encountered
                } else if (c == 'b') {
                    state = 2;  // Transition back to state 2 if 'b' encountered
                } else {
                    state = 6;  // Invalid character for this state
                }
                break;

            case 4:
                if (c == 'a') {
                    state = 6;  // Invalid transition for 'a'
                } else if (c == 'b') {
                    state = 5;
                } else {
                    state = 6;  // Invalid character for this state
                }
                break;

            case 5:
                if (c == 'a') {
                    state = 6;  // Invalid transition for 'a'
                } else if (c == 'b') {
                    state = 2;  // Transition back to state 2 if 'b' encountered
                } else {
                    state = 6;  // Invalid character for this state
                }
                break;

            case 6:
                printf("\n%s is not recognised.\n", s);
                exit(0);  // Exit the program as the string is unrecognized
        }
    }

    // Final output based on the last state
    if (state == 1) {
        printf("\n%s is accepted under rule 'a'\n", s);
    } else if (state == 2 || state == 4) {
        printf("\n%s is accepted under rule 'a*b+'\n", s);
    } else if (state == 5) {
        printf("\n%s is accepted under rule 'abb'\n", s);
    } else {
        printf("\n%s is not accepted.\n", s);
    }

    return 0;
}
