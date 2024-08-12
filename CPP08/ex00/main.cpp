/**
 * @file main.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Test the easyfind function with various containers.
 * @date 2024-08-06
 */

#include "Easyfind.hpp"

#include <vector>
#include <iostream>
#include <deque>
#include <list>

/**
 * @brief Test the easyfind function on a given container.
 *
 *
 * @tparam T The type of the container.
 * @param container The container in which to search for the element.
 * @param toFind The element to find in the container.
 */
template <typename T>
void	testContainer( T &container, int toFind ) {
	try {
		easyfind(container, toFind);
		std::cout << GREEN << "The number " << toFind << " is in the container." << RESET << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}	
}

/**
 * @brief Entry point of the program.
 *
 * This function tests the easyfind function with different types of sequence containers
 * (vector, deque, list) and prints the results.
 *
 * @return int Returns 0 on successful execution.
 */
int	main( void ) {
	std::cout << "--- VECTOR ---" << std::endl;
	std::vector<int>	v;
	for (int i = 1; i < 6; i++) {
		v.push_back(i);
	}
	testContainer(v, 4);
	testContainer(v, 7);

	std::cout << "--- DEQUE ---" << std::endl;
	std::deque<int>		d;
	for (int i = 1; i < 6; i++) {
		if (i % 2 == 0) {
			d.push_back(i);
		} else {
			d.push_front(i);
		}
	}
	testContainer(v, 4);
	testContainer(v, 7);

	std::cout << "--- LIST ---" << std::endl;
	std::list<int>		l;
	for (int i = 1; i < 6; i++) {
		if (i % 2 == 0) {
			l.push_front(i);
		} else {
			l.push_back(i);
		}
	}
	testContainer(v, 4);
	testContainer(v, 7);
}