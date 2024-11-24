#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_NONTERMINALS 5
#define MAX_TERMINALS 5
#define MAX_INPUT_LENGTH 50

// Grammar representations
char nonTerminals[MAX_NONTERMINALS] = {'S', 'A', 'B'};
char terminals[MAX_TERMINALS] = {'a', 'b', '$'};
char productions[MAX_PRODUCTIONS][2][MAX_INPUT_LENGTH] = {
    {"S", "AB"},
    {"A", "aA"},
    {"A", "b"},
    {"B", "a"},
    {"B", "bB"},
};

// FIRST sets
char FIRST[MAX_NONTERMINALS][MAX_TERMINALS] = {
    {'a', 'b'},  // FIRST(S) -> a, b
    {'a', 'b'},  // FIRST(A) -> a, b
    {'a', 'b'}   // FIRST(B) -> a, b
};

// FOLLOW sets
char FOLLOW[MAX_NONTERMINALS][MAX_TERMINALS] = {
    {'$', 'a', 'b'},  // FOLLOW(S) -> $, a, b
    {'$', 'a', 'b'},  // FOLLOW(A) -> $, a, b
    {'$', 'a', 'b'}   // FOLLOW(B) -> $, a, b
};

// LL(1) parsing table
char LL1_Table[MAX_NONTERMINALS][MAX_TERMINALS][MAX_INPUT_LENGTH];

// Function to find the index of a non-terminal
int getNonTerminalIndex(char nonTerminal) {
    for (int i = 0; i < MAX_NONTERMINALS; i++) {
        if (nonTerminals[i] == nonTerminal) {
            return i;
        }
    }
    return -1;
}

// Function to find the index of a terminal
int getTerminalIndex(char terminal) {
    for (int i = 0; i < MAX_TERMINALS; i++) {
        if (terminals[i] == terminal) {
            return i;
        }
    }
    return -1;
}

// Function to fill the LL(1) parsing table
void buildLL1ParsingTable() {
    for (int i = 0; i < MAX_NONTERMINALS; i++) {
        for (int j = 0; j < MAX_TERMINALS; j++) {
            strcpy(LL1_Table[i][j], "");
        }
    }

    for (int i = 0; i < MAX_PRODUCTIONS; i++) {
        char *lhs = productions[i][0];
        char *rhs = productions[i][1];

        int nonTerminalIndex = getNonTerminalIndex(lhs[0]);
        for (int j = 0; j < strlen(rhs); j++) {
            char symbol = rhs[j];
            if (symbol == 'a' || symbol == 'b') {
                int terminalIndex = getTerminalIndex(symbol);
                strcpy(LL1_Table[nonTerminalIndex][terminalIndex], rhs);
                break;
            }
        }
    }
}

// Function to parse the input string
void parseString(char *input) {
    int stack[MAX_INPUT_LENGTH];
    int top = -1;

    stack[++top] = getNonTerminalIndex('S');  // Push start symbol (S) onto stack

    int inputIndex = 0;
    while (top >= 0) {
        int currentNonTerminal = stack[top--];
        char currentSymbol = terminals[input[inputIndex] - 'a'];

        // If the symbol on top of the stack is a terminal
        if (currentSymbol == input[inputIndex]) {
            printf("Matching: %c\n", currentSymbol);
            inputIndex++;
        } else if (currentSymbol == '$') {
            break;
        } else {
            int nextNonTerminal = getNonTerminalIndex(currentSymbol);
            // Get the right-hand side of the production rule
            char *rhs = NULL;
            for (int i = 0; i < MAX_PRODUCTIONS; i++) {
                if (productions[i][0][0] == currentSymbol) {
                    rhs = productions[i][1];  // Store the right-hand side
                    break;
                }
            }
            if (rhs != NULL) {
                // Copy the right-hand side into the parsing table
                strcpy(LL1_Table[nextNonTerminal][getTerminalIndex(input[inputIndex])], rhs);
            }
        }
    }
}

int main() {
    // Build the LL(1) parsing table
    buildLL1ParsingTable();
    printf("LL(1) Parsing Table:\n");

    for (int i = 0; i < MAX_NONTERMINALS; i++) {
        printf("%c: ", nonTerminals[i]);
        for (int j = 0; j < MAX_TERMINALS; j++) {
            if (strlen(LL1_Table[i][j]) > 0) {
                printf("%s\t", LL1_Table[i][j]);
            } else {
                printf("empty\t");
            }
        }
        printf("\n");
    }

    // Test the parser
    char input[MAX_INPUT_LENGTH];
    printf("\nEnter a string to parse: ");
    scanf("%s", input);

    parseString(input);

    return 0;
}
