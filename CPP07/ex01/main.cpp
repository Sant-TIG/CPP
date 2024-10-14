/**
 * @file main.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Demonstration of the `iter` function template with different types.
 * @date 2024-08-12
 */

#include "Iter.hpp"

#include <iostream>

/**
 * @brief Function template that prints an element to the standard output.
 *
 * @tparam T The type of the element to print.
 * @param element The element to be printed.
 */
template <typename T>
void	printElement( T element ) {
	std::cout << "Elemento: " << element << std::endl;
}

/**
 * @brief Main function demonstrating the use of the `iter` function template.
 */
int main() {
	int myArray[] = {1, 2, 3, 4, 5};
	::iter(myArray, 5, printElement<int>);

	double myArray2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(myArray2, 5, printElement<double>);

	std::string myArray3[] = {"Hola", "que", "pasa", "eh", "tu"};
	::iter(myArray3, 5, printElement<std::string>);

	return 0;
}