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
void generate_starting_food(char32_t field[HEIGHT][WIDTH]);

char32_t field[HEIGHT][WIDTH];

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    //MARK: for tests
    int counter = 0;

    //MARK: setup
    fill_field(field);
    generate_starting_food(field);

    while (true) {
        newScreen();
        std::cout << "Hello, world!" << " " << counter << std::endl;
        print_field(field);

        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
