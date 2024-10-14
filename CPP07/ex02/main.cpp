#include <iostream>
# include <stdlib.h>
# include <ctime>

#include "Array.hpp"

#define SIZE 10

int main(int, char**)
{
    Array<int> numbers((unsigned int)SIZE);
   	std::srand(std::time(NULL));
    for (int i = 0; i < SIZE; i++) {
        const int value = rand() % SIZE;
        numbers[i] = value;
    }
    for (int i = 0; i < SIZE; i++) {
        std::cout << numbers[i] << std::endl;
    }
    try {
        numbers[-2] = 0;
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    } try {
        numbers[SIZE] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    } try {
		for (int i = 0; i < SIZE; i++) {
            std::cout << "Old: " << numbers[i] << std::endl;
			numbers[i] = rand() % SIZE;
            std::cout << "New: " << numbers[i] << std::endl;
		}
	} catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    } try{
		Array<int> n(0);
		std::cout << "array of empty size" << std::endl;
	} catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}