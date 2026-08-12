#include <iostream>
#include <thread>
#include <chrono>
#include "config.h"
#ifdef _WIN32
#include <windows.h>
#endif

void fill_field(char32_t field[HEIGHT][WIDTH]);
void print_field(const char32_t field[HEIGHT][WIDTH]);
void newScreen();
void deathScreen();

void generate_starting_food(char32_t field[HEIGHT][WIDTH]);
void generate_mother_ant(char32_t field[HEIGHT][WIDTH]);
int count_empty_near_mother_ant(char32_t field[HEIGHT][WIDTH]);
int count_food_near_mother_ant(char32_t field[HEIGHT][WIDTH]);


char32_t field[HEIGHT][WIDTH];

int mother_ant_hunger = MOTHER_ANT_HUNGER_TIMER;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    //MARK: for tests
    int counter = 0;
    bool alive = true;

    //MARK: setup
    fill_field(field);
    generate_starting_food(field);

    //MARK: generate mother ant
    generate_mother_ant(field);

    while (alive) {
        newScreen();
        std::cout << "Tick: " <<  counter << " | " << "Mother ant hunger: " << mother_ant_hunger << std::endl;
        print_field(field);
        std::cout << "Empty: " << count_empty_near_mother_ant(field) << " | " << "Food: " << count_food_near_mother_ant(field) << std::endl;

        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        mother_ant_hunger--;

        if (mother_ant_hunger <= 0) {
            newScreen();
            deathScreen();
            alive=false;
        }
    }

    return 0;
}
