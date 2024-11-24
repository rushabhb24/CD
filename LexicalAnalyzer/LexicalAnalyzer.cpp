#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

// Function declaration
void keyw(const string &p);

// Global counters
int i = 0, id = 0, kw = 0, num = 0, op = 0;

// List of keywords
string keys[32] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

int main() {
    char ch;
    string str;
    string seps = " \t\n,;(){}[]#\"<>";    // separators
    string oper = "!%^&*-+=~|.<>/?";       // operators

    // Directly set the file path
    string fname = "C:\\Users\\Admin\\Documents\\CD practical\\CD practical\\sample.c";

    ifstream file(fname);  // Open the file

    // Check if the file is open
    if (!file) {
        cout << "File not found!" << endl;
        return 1;
    }

    // Process each character in the file
    while (file.get(ch)) {
        bool isOperator = false;

        // Check for operators
        for (char opChar : oper) {
            if (ch == opChar) {
                cout << ch << " is an operator" << endl;
                op++;
                keyw(str);  // Process the token before the operator
                str.clear();  // Clear the current token string
                isOperator = true;
                break;
            }
        }

        // If not an operator, process separators
        if (!isOperator) {
            bool isSeparator = false;
            for (char sepChar : seps) {
                if (ch == sepChar) {
                    // Handle preprocessor directives (e.g., #include)
                    if (ch == '#') {
                        cout << ch;
                        while (file.get(ch) && ch != '>') {
                            cout << ch;
                        }
                        cout << ch << " is a header file" << endl;
                        str.clear();  // Clear the current token string
                        isSeparator = true;
                        break;
                    }

                    // Handle string literals (e.g., "hello")
                    if (ch == '"') {
                        cout << ch;
                        do {
                            file.get(ch);
                            cout << ch;
                        } while (ch != '"');
                        cout << " is an argument" << endl;
                        str.clear();  // Clear the current token string
                        isSeparator = true;
                        break;
                    }

                    // Process token before separator
                    keyw(str);
                    str.clear();  // Clear the current token string
                    isSeparator = true;
                    break;
                }
            }

            // If not a separator, accumulate the characters for the token
            if (!isSeparator) {
                str += ch;  // Add the current character to the token string
            }
        }
    }

    // Close the file
    file.close();

    // Output the results
    cout << "\nKeywords: " << kw;
    cout << "\nIdentifiers: " << id;
    cout << "\nOperators: " << op;
    cout << "\nNumbers: " << num << endl;

    return 0;
}

// Function to classify the token (keyword, identifier, or number)
void keyw(const string &p) {
    int flag = 0;

    // Check if the token is a keyword
    for (int k = 0; k < 32; k++) {
        if (keys[k] == p) {
            cout << p << " is a keyword" << endl;
            kw++;
            flag = 1;
            break;
        }
    }

    // If not a keyword, classify it as a number or identifier
    if (flag == 0) {
        if (isdigit(p[0])) {
            cout << p << " is a number" << endl;
            num++;
        } else if (!p.empty()) {
            cout << p << " is an identifier" << endl;
            id++;
        }
    }

    i = -1;  // Reset the token index after processing
}
