#include "config.h"
#include "symbols.h"

void change_pixel_state(char32_t *pixel, char32_t symbol)
{
    *pixel = symbol;
}

void generate_starting_food(char32_t field[FIELD_SIZE][FIELD_SIZE])
{
    int i, j;
    for (i = FIELD_SIZE / 2; i > 0; i--)
        for (j = FIELD_SIZE - 1; j > FIELD_SIZE / 2; j--)
            change_pixel_state(&field[i][j], FOOD);
}
