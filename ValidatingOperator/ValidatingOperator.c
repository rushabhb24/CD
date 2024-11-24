#include <stdio.h>

int main() {
    char s[3], ch = 'y';

    do {
        printf("\nEnter any operator: ");
        scanf("%s", s);  // Input operator

        // Check operator and output corresponding message
        switch (s[0]) {
            case '>':
                if (s[1] == '=') {
                    printf("\nValid operator: Greater than or equal");
                } else {
                    printf("\nValid operator: Greater than");
                }
                break;
            case '<':
                if (s[1] == '=') {
                    printf("\nValid operator: Less than or equal");
                } else {
                    printf("\nValid operator: Less than");
                }
                break;
            case '=':
                if (s[1] == '=') {
                    printf("\nValid operator: Equal to");
                } else {
                    printf("\nValid operator: Assignment");
                }
                break;
            case '!':
                if (s[1] == '=') {
                    printf("\nValid operator: Not Equal");
                } else {
                    printf("\nValid operator: Bitwise Not");
                }
                break;
            case '&':
                if (s[1] == '&') {
                    printf("\nValid operator: Logical AND");
                } else {
                    printf("\nValid operator: Bitwise AND");
                }
                break;
            case '|':
                if (s[1] == '|') {
                    printf("\nValid operator: Logical OR");
                } else {
                    printf("\nValid operator: Bitwise OR");
                }
                break;
            case '+':
                if (s[1] == '+') {
                    printf("\nValid operator: Increment");
                } else {
                    printf("\nValid operator: Addition");
                }
                break;
            case '-':
                if (s[1] == '-') {
                    printf("\nValid operator: Decrement");
                } else {
                    printf("\nValid operator: Subtraction");
                }
                break;
            case '*':
                printf("\nValid operator: Multiplication");
                break;
            case '/':
                printf("\nValid operator: Division");
                break;
            case '%':
                printf("\nValid operator: Modulus");
                break;
            default:
                printf("\nInvalid operator!!!!");
                break;
        }

        // Ask user if they want to continue
        printf("\nDo you want to continue (y: Yes, n: No): ");
        scanf(" %c", &ch);  // Ensure a space before %c to consume any leftover newline

    } while (ch == 'Y' || ch == 'y');

    return 0;
}
