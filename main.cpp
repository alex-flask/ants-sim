#include <iostream>
#include <thread>
#include <chrono>

#define FIELD_SIZE 16

void fill_field();
void print_field();
void newScreen();

std::string field[FIELD_SIZE][FIELD_SIZE];

int main()
{
    //MARK: setup
    fill_field();

    while (true) {
        std::cout << "Hello, world!" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));       
    }

    return 0;
}

void fill_field()
{
    int i, j;
    for (i = 0; i < FIELD_SIZE; i++)
        for (j = 0; j < FIELD_SIZE; j++)
            field[i][j] = " ";
}

void print_field()
{
}

void newScreen()
{
}
