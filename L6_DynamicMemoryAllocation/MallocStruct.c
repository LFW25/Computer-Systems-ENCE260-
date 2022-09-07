# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct {
    char random;
    int8_t junk;
} Data_t;

Data_t* newData(char random, int8_t junk)
{
    Data_t* newDatat = malloc(sizeof(Data_t));
    newDatat->random = random;
    newDatat->junk = junk;
    return newDatat;
}

void freeData(Data_t* data)
{
    free(data);
}

int main(void)
{
    Data_t* data = newData('A', 1);
    printf("%c %d\n", data->random, data->junk);
    freeData(data);
}