#   include <stdint.h>
#   include <stdbool.h>
#   include <stdio.h>
#   include <ctype.h>

int main(int argc, char** argv)
{
    size_t i;
    for (i = 0; i < argc; i++) {
        printf("[%ld] %s\n", i, argv[i]);
    }
}
