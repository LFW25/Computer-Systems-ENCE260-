#   include <stdint.h>
#   include <stdbool.h>
#   include <stdio.h>
#   include <ctype.h>

int main(void)
{
    int c;
    do {
    
        c = getchar();
        if (c != -1) {
            printf("%d\n", c);
        } else if (c == '\012') {
            printf("\'\\n\'\n");
        } else {
            if (c.isdigit()) {
                printf("Digit %d\n", c);
            } else if (c.isalpha()) {
                printf("Letter %c\n", c);
            } else {
                printf("Non-alphanumeric"\n);
            }
    } while (c != -1);
    
}
