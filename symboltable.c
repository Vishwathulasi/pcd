#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAR 25
#define MAX_INPUT 50

struct SymTab {
	int lineno;
	char var[MAX_VAR];
	char dt[MAX_VAR];
	char val[MAX_VAR];
};

// Helper function to convert a string to lowercase
void toLower(char *str) {
	int i = 0;
	while (str[i]) {
		str[i] = tolower(str[i]);
		i++;
	}
}

int main() {
	struct SymTab sa[MAX_INPUT];
	int i = 0, line = 0;
	char s[MAX_VAR], typ[MAX_VAR];
	char *input[] = {
		"int", "a", ",", "b", "=", "5", ";",
		"float", "c", ";",
		"char", "d", "=", "a", ";",
		"double", "x", "=", "21.7899", ";",
		"char", "v", "=", "f", ";"
	};
	int idx = 0;

	printf("\n\nSYMBOL TABLE MANAGEMENT\n\n");
	printf("Variable\tDatatype\tLine.no.\tValue\n");

	while (idx < sizeof(input) / sizeof(input[0])) {
		strcpy(s, input[idx++]);
		char lowerS[MAX_VAR];
		strcpy(lowerS, s);
		toLower(lowerS);  // Convert to lowercase

		// Check if it's a datatype (including "double")
		if (strcmp(lowerS, "int") == 0 || strcmp(lowerS, "float") == 0 || strcmp(lowerS, "char") == 0 || strcmp(lowerS, "double") == 0) {
			strcpy(typ, lowerS);  // Store the data type in lowercase
			line++;

			while (strcmp(s, ";") != 0) {
				struct SymTab entry;  // Declare the struct variable before the loop
				entry.lineno = line;
				strcpy(entry.dt, typ);

				strcpy(s, input[idx++]);
				strcpy(entry.var, s);
				strcpy(s, input[idx++]);

				// Check if there's an assignment
				if (strcmp(s, "=") == 0) {
					strcpy(s, input[idx++]);
					strcpy(entry.val, s);
					strcpy(s, input[idx++]);
				} else {
					strcpy(entry.val, "garbage");
				}

				sa[i] = entry;  // Assign the entry to the array
				i++;  // Increment the index

				// If there's a comma, continue with the next variable
				if (strcmp(s, ",") == 0) {
					continue;
				} else {
					break;
				}
			}
		}
	}

	int j; // Declare j variable outside the loop

	// Print the symbol table
	for (j = 0; j < i; j++) {
		printf("%s\t%s\t%d\t%s\n", sa[j].var, sa[j].dt, sa[j].lineno, sa[j].val);
	}

	return 0;
}
