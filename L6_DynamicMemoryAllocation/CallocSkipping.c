# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>

char* skipping(const char* string, size_t n)
{
    size_t destLength = ((n + 1)/2) + 1;

    char* newString = calloc(destLength, sizeof(char));
    
    for (size_t j = 0; j < destLength-1; j++) {
        newString[j] = string[2*j];
    }

    return newString;
}

int main(void)
{
    char borkedString[] = {'h', 'i', '!', '\0', 'A', 'B'};
    char* s = skipping("0123456789", 10);
    printf("%s\n", s);
    free(s);

    char* a = skipping("A0B1C2D", 7);
    printf("%s\n", a);
    free(a);

    char* b = skipping("", 0);
    printf("%s\n", b);
    free(b);

    char* c = skipping("X", 1);
    printf("%s\n", c);
    free(c);

    char* d = skipping(borkedString, 3);
    printf("%s\n", d);
    free(d);
}