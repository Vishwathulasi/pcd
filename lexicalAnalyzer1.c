#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a keyword
void checkIsKeyword(char str[]) {
    int isKeyword = 0;
    const char *keywords[] = {"int", "main", "float", "double", "char", "string", "for", "do", "while", "if", "else"};
    int i;
    for (i = 0; i < 11; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            isKeyword = 1;
            break;
        }
    }
    printf("\n%s is a %s", str, isKeyword ? "Keyword" : "Identifier");
}

int main() {
    char input[1000], str[100];
    char operators[100], specialCharacters[100];
    int constants[100], numIndex = 0, opIndex = 0, scIndex = 0;
    int k = 0;
    int i;  // Declare iterator variable outside the loop

    printf("Enter the C program (end with ~):\n");
    scanf("%[^~]", input);  // Read until ~ to mark the end of input

    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (isdigit(c)) {
            int t = c - '0';
            while (isdigit(input[++i])) {
                t = t * 10 + (input[i] - '0');
            }
            i--;  // Step back to adjust the loop index
            constants[numIndex++] = t;
        } else if (isalpha(c)) {
            str[k++] = c;
            while (isalnum(input[++i]) || input[i] == '_' || input[i] == '$') {
                str[k++] = input[i];
            }
            str[k] = '\0';
            checkIsKeyword(str);
            k = 0;
            i--;  // Step back to adjust the loop index
        } else if (strchr("+-*/%&^<>=", c)) {
            operators[opIndex++] = c;
        } else if (!isspace(c)) {
            specialCharacters[scIndex++] = c;
        }
    }

    printf("\n\nThe constants are: ");
    for (i = 0; i < numIndex; i++) {  // Reuse `i` for other loops
        printf("%d ", constants[i]);
    }

    printf("\nThe operators are: ");
    for (i = 0; i < opIndex; i++) {
        printf("%c ", operators[i]);
    }

    printf("\nThe special characters are: ");
    for (i = 0; i < scIndex; i++) {
        printf("%c ", specialCharacters[i]);
    }

    return 0;
}
