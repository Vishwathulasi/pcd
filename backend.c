#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char a[100], mov[] = "MOVF", mul[] = "MULF", div[] = "DIVF", add[] = "ADDF", sub[] = "SUBF";
    int i = 0, j = 0, len = 0, s = 0, r = 1;
    printf("\nEnter the code: ");
    fgets(a, sizeof(a), stdin);
    len = strlen(a);
    if (a[len - 1] == '\n') {
        a[len - 1] = '\0';
        len--;
    }

    for (i = 0; i < len; i++) {
        if (a[i] == '=') {
            for (j = i; j < len; j++) {
                if (a[j] == 'i') {
                    printf("\n%s %c%c%c,R%d", mov, a[j], a[j + 1], a[j + 2], r++);
                }
            }
        } else if (isdigit(a[i]) && isdigit(a[i + 1])) {
            printf("\n%s #%c%c,R%d", mov, a[i], a[i + 1], r++);
        }
    }
    for (i = len - 1; i >= 0; i--) {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            s = a[i - 1] - '0' - 1;
            if (a[i] == '+') {
                printf("\n%s ", add);
            } else if (a[i] == '-') {
                printf("\n%s ", sub);
            } else if (a[i] == '*') {
                printf("\n%s ", mul);
            } else if (a[i] == '/') {
                printf("\n%s ", div);
            }

            if (a[i + 1] == 'i') {
                printf("R%d,R%d", s, a[i + 3] - '0' - 1);
            } else {
                printf("R%d,R%d", s, r - 1);
            }
            r--;
        }
    }
    //Enter the code: id1=id2*id3+id4
    printf("\n%s id1,R1", mov);
    return 0;
}
