#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    char c;
    int state = 0, i = 0;

    // Prompt for input
 cout << "\nEnter a string: ";
    // s="aab";
    getline(cin, s); // Use getline to input the string (handles spaces too)

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
                cout << "\n" << s << " is not recognised." << endl;
                return 0;  // Exit the program as the string is unrecognized
        }
    }

    // Final output based on the last state
    if (state == 1) {
        cout << "\n" << s << " is accepted under rule 'a'\n";
    } else if (state == 2 || state == 4) {
        cout << "\n" << s << " is accepted under rule 'a*b+'\n";
    } else if (state == 5) {
        cout << "\n" << s << " is accepted under rule 'abb'\n";
    } else {
        cout << "\n" << s << " is not accepted.\n";
    }

    return 0;
}
