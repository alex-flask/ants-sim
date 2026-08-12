#include <iostream>
#include "config.h"

void fill_field(std::string field[FIELD_SIZE][FIELD_SIZE])
{
    int i, j;
    for (i = 0; i < FIELD_SIZE; i++)
        for (j = 0; j < FIELD_SIZE; j++)
            if (i==0 || j==0 || i==FIELD_SIZE-1 || j==FIELD_SIZE-1)
                field[i][j] = "#";
            else
                field[i][j] = " ";
}

void print_field(std::string field[FIELD_SIZE][FIELD_SIZE])
{
    int i, j;
    for (i = 0; i < FIELD_SIZE; i++) {
        for (j = 0; j < FIELD_SIZE; j++)
            std::cout << field[i][j];
        std::cout << std::endl;
    }
}

void newScreen()
{
    printf("\033[2J\033[H");
}
