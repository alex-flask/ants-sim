#include <iostream>
#include "config.h"
#include "symbols.h"

void fill_field(char32_t field[FIELD_SIZE][FIELD_SIZE])
{
    int i, j;
    for (i = 0; i < FIELD_SIZE; i++)
        for (j = 0; j < FIELD_SIZE; j++)
            if (i==0 || j==0 || i==FIELD_SIZE-1 || j==FIELD_SIZE-1)
                field[i][j] = BARRIER;
            else
                field[i][j] = EMPTY;
}

void print_field(const char32_t field[FIELD_SIZE][FIELD_SIZE])
{
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        for (int j = 0; j < FIELD_SIZE; j++)
        {
            switch (field[i][j])
            {
                case FOOD:
                    std::cout << "•";
                    break;

                default:
                    std::cout << static_cast<char>(field[i][j]);
                    break;
            }
        }

        std::cout << '\n';
    }
}

void newScreen()
{
    printf("\033[2J\033[H");
}
