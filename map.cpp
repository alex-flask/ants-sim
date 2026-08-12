#include "config.h"
#include "symbols.h"

void change_pixel_state(char32_t *pixel, char32_t symbol)
{
    *pixel = symbol;
}

void generate_starting_food(char32_t field[HEIGHT][WIDTH])
{
    int i, j;
    for (i = HEIGHT / 2; i > 0; i--)
        for (j = WIDTH - 2; j > WIDTH / 2; j--)
            change_pixel_state(&field[i][j], FOOD);
}
