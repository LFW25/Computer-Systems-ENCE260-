# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>

int main(void)
{
    uint64_t* dynAlloc = malloc(sizeof(uint64_t));
    scanf("%ld", dynAlloc);
    printf("%ld\n", *dynAlloc);
    free(dynAlloc);
}