#include <iostream>
#include "config.h"
#include "symbols.h"

void fill_field(char32_t field[HEIGHT][WIDTH])
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < WIDTH; j++)
            if (i==0 || j==0 || i==HEIGHT-1 || j==WIDTH-1)
                field[i][j] = BARRIER;
            else
                field[i][j] = EMPTY;
}

void print_field(const char32_t field[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
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

void deathScreen(int score)
{
    std::cout << "=================+++=================" << std::endl;
    std::cout << "   " << "Mother ant starved to death!" << std::endl;
    std::cout << " " << "Ants have survived for: " << score << " seconds" << std::endl;
    std::cout << "=================+++=================" << std::endl;
}

void newScreen()
{
    printf("\033[2J\033[H");
}
