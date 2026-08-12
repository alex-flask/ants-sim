#include <iostream>
#include "config.h"
#include "symbols.h"
#include <random>

int mother_ant_i;
int mother_ant_j;

void change_pixel_state(char32_t *pixel, char32_t symbol)
{
    *pixel = symbol;
}

void generate_mother_ant(char32_t field[HEIGHT][WIDTH])
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr_y(1, HEIGHT-2); // define the range
    mother_ant_i = distr_y(gen);
    std::uniform_int_distribution<> distr_x(1, WIDTH-2);
    mother_ant_j = distr_x(gen);
    std::cout << "Mother ant generated at (" << mother_ant_i << ", " << mother_ant_j << ")" << std::endl;
    change_pixel_state(&field[mother_ant_i][mother_ant_j], ANT_MOTHER);
}

void generate_starting_food(char32_t field[HEIGHT][WIDTH])
{
    int i, j;
    for (i = HEIGHT / 2; i > 0; i--)
        for (j = WIDTH - 2; j > WIDTH / 2; j--)
            change_pixel_state(&field[i][j], FOOD);
}

int count_empty_near_mother_ant(char32_t field[HEIGHT][WIDTH])
{
    int empty_spaces = 0;
    for (int i = mother_ant_i - 1; i <= mother_ant_i + 1; i++)
        for (int j = mother_ant_j - 1; j <= mother_ant_j + 1; j++)
            if (field[i][j] == EMPTY)
            empty_spaces++;
    return empty_spaces;
}

int count_food_near_mother_ant(char32_t field[HEIGHT][WIDTH])
{
    int food_nearby = 0;
    for (int i = mother_ant_i - 1; i <= mother_ant_i + 1; i++)
        for (int j = mother_ant_j - 1; j <= mother_ant_j + 1; j++)
            if (field[i][j] == FOOD)
            food_nearby++;
    return food_nearby;
}
