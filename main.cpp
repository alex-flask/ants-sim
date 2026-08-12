#include <iostream>
#include <thread>
#include <chrono>
#include "config.h"

void fill_field(std::string field[FIELD_SIZE][FIELD_SIZE]);
void print_field(std::string field[FIELD_SIZE][FIELD_SIZE]);
void newScreen();

std::string field[FIELD_SIZE][FIELD_SIZE];

int main()
{
    //MARK: for tests
    int counter = 0;

    //MARK: setup
    fill_field(field);

    while (true) {
        newScreen();
        std::cout << "Hello, world!" << " " << counter << std::endl;
        print_field(field);

        counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));       
    }

    return 0;
}

