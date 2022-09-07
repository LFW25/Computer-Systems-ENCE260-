#   include <stdint.h>
#   include <stdbool.h>
#   include <stdio.h>
#   include <ctype.h>

int main(void)
{
    int c;
    do {
    
        c = getchar();
        if ((c != -1) && (c == '\012')) {
            printf("\'\\n\'\n");

        } else if ((c != -1) && (c != '\012')) {
            printf("\'%c\': ", c);

            if (isdigit(c)) {
                printf("Digit %c\n", c);

            } else if (isalpha(c)) {
                if (c < 92) {
                    printf("Letter %d\n", c-'A' + 1);
                } else {
                    printf("Letter %d\n", c-'a' + 1);
                }
            } else {
                printf("Non-alphanumeric\n");
            }
        }
    } while (c != -1);
    
}
