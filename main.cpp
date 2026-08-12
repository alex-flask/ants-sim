#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "config.h"
#ifdef _WIN32
#include <windows.h>
#endif

#define NEED_STARTING_FOOD 0

void fill_field(char32_t field[HEIGHT][WIDTH]);
void print_field(const char32_t field[HEIGHT][WIDTH]);
void newScreen();
void generate_starting_food(char32_t field[HEIGHT][WIDTH]);
void generate_food(char32_t field[HEIGHT][WIDTH]);

char32_t field[HEIGHT][WIDTH];

int mother_ant_hunger = MOTHER_ANT_HUNGER_TIMER;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    //MARK: for tests
    int counter = 0;

    //MARK: setup
    fill_field(field);
    std::srand(std::time(0));

    if (NEED_STARTING_FOOD)
        generate_starting_food(field);

    while (true) {
        newScreen();
        std::cout << "Tick: " <<  counter << " | " << "Mother ant hunger: " << mother_ant_hunger << std::endl;
        generate_food(field);
        print_field(field);

        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        mother_ant_hunger--;
    }

    return 0;
}
