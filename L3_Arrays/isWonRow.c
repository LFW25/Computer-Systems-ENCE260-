#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool isWonRow(char player, const char game[3][3], uint8_t rowNum)
{
    char first, second, third;
    first = game[rowNum][0];
    second = game[rowNum][1];
    third = game[rowNum][2];

    if ((first == second) && (second == third) && (third == player)) {
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    char game1[3][3] = {{'X', 'O', ' '},{'X', 'X', 'X'}, {' ', ' ', ' '}};
    printf(isWonRow('X', game1, 1) ? "true\n" : "false\n");

    const char game2[3][3] = {{'X', 'O', ' '},{' ', ' ', ' '}, {'X', 'X', 'O'}};
    printf(isWonRow('X', game2, 2) ? "true\n" : "false\n");
}
