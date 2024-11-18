#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main()
{
    char a[25], b[25];
    int i=0, j=0, k=0, count=0, ti=0;
    
    printf("Enter the code : ");
    scanf("%s", a);  // Read input code
    strcpy(b, a);    // Copy the input to b
    
    // Process multiplication and division first
    for(i=0; i<strlen(b); i++) {
        if(b[i] == '*' || b[i] == '/') {
            // Find where the expression starts (i.e., the last non-operator before the current operator)
            for(j=i-1; b[j] != '+' && b[j] != '-' && b[j] != '*' && b[j] != '/' && b[j] != '='; j--);
            k = j + 1;
            count = 0;
            printf("\nt%d = ", ti++);  // Print temporary variable for result
            
            // Extract the expression
            for(j = j + 1; count < 2 && b[j] != '\0'; j++) {
                if(b[j+1] == '+' || b[j+1] == '-' || b[j+1] == '*' || b[j+1] == '/') 
                    count++;
                printf("%c", b[j]);
            }
            
            // Create temporary variable (t0, t1, etc.)
            b[k++] = 't';
            b[k++] = ti - 1 + '0';  // Convert the number to char
            
            // Shift remaining part of the string
            for(j = j, k = k; k < strlen(b); j++, k++) {
                b[k] = b[j];
            }
            i = 0; // Reset index
        }
    }
    
    // Process addition and subtraction next
    for(i = 0; i < strlen(b); i++) {
        if(b[i] == '+' || b[i] == '-') {
            for(j = i - 1; b[j] != '+' && b[j] != '-' && b[j] != '='; j--);
            k = j + 1;
            count = 0;
            printf("\nt%d = ", ti++);  // Print temporary variable for result
            
            // Extract the expression
            for(j = j + 1; count < 2 && b[j] != '\0'; j++) {
                if(b[j+1] == '+' || b[j+1] == '-') 
                    count++;
                printf("%c", b[j]);
            }
            
            // Create temporary variable (t0, t1, etc.)
            b[k++] = 't';
            b[k++] = ti - 1 + '0';  // Convert the number to char
            
            // Shift remaining part of the string
            for(j = j, k = k; k < strlen(b); j++, k++) {
                b[k] = b[j];
            }
        }
    }
    
    // Print the final result after replacing expressions
    printf("\n%s", b);
    
    //Enter the code : d=a+b*c
}
