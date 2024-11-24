#include <stdio.h>
#include <string.h>

int main() {
    char string[20];
    int state = 0, count = 0;

    printf("\n The string must begin with 'a' and terminate with 'b'\n");
    printf("The Grammar Is:\n");
    printf("\tS -> aS\n\tS -> Sb\n\tS -> ab\n");

    printf("Enter The String To Be Checked: ");
    fgets(string, sizeof(string), stdin); // Safe alternative to gets()

    // Remove trailing newline if present
    string[strcspn(string, "\n")] = '\0';

    while (string[count] != '\0') {
        switch (state) {
            case 0:
                if (string[count] == 'a') 
                    state = 1;
                else 
                    state = 3;  // Invalid input
                break;

            case 1:
                if (string[count] == 'a') 
                    state = 1;  // Stay in state 1 if 'a' is encountered
                else if (string[count] == 'b') 
                    state = 2;  // Transition to state 2 when 'b' is encountered
                else 
                    state = 3;  // Invalid character
                break;

            case 2:
                if (string[count] == 'b') 
                    state = 2;  // Stay in state 2 if 'b' is encountered
                else 
                    state = 3;  // Invalid character
                break;

            default:
                break;
        }

        count++;

        // Exit the loop if an invalid state is reached
        if (state == 3)
            break;
    }

    // If the string ends at state 2, it is accepted
    if (state == 2)
        printf("\nString is accepted\n");
    else
        printf("\nString is not accepted\n");

    return 0;
}
