/**
 * @file main.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Testing the Span class with different scenarios.
 * @date 2024-08-06
 */

#include "Span.hpp"

#include <ctime>
#include <cstdlib>

/**
 * @brief Tests the Span class by adding a sequence of random numbers.
 *
 * This function creates a Span object with a given capacity, fills a vector with random integers,
 * and adds them to the Span object. It then prints the shortest and longest spans.
 *
 * @param capacity The number of elements to generate and add to the Span object.
 */
void    testSequence( int capacity ) {
    std::cout << GREEN << "\nSequence tests\n" << RESET << std::endl;
    try {
        Span                span(capacity);
        std::vector<int>    v1;
        v1.reserve(capacity);
        srand(time(0));
		for (int i = 0; i < capacity; ++i) {
            v1.push_back(rand() % capacity);
        }
        span.addSequence(v1.begin(), v1.end());
        std::cout << "Span created with " << capacity << " numbers." << std::endl;
        std::cout << "Capacity: " << span.getN() << std::endl;
        //span.printVector();
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	} catch (const std::length_error &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    } catch (const std::logic_error &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
	} catch(const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Tests the Span class by adding individual random numbers.
 *
 * This function creates a Span object with a given capacity, adds random integers one by one,
 * and then prints the shortest and longest spans. It also tries to add an extra number beyond
 * the Span's capacity to test exception handling.
 *
 * @param capacity The number of elements to generate and add to the Span object.
 */
void    testSpan( int capacity ) {
    std::cout << GREEN << "\nSpan tests\n" << RESET << std::endl;
    try {
        Span    span(capacity);
        srand(time(0));
        for (int i = 0; i < capacity; i++) {
            span.addNumber(rand() % capacity);
        }
        std::cout << "Span created with " << capacity << " numbers." << std::endl;
        std::cout << "Capacity: " << span.getN() << std::endl;
        span.printVector();
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
        span.addNumber(99);
    } catch (const std::length_error &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    } catch (const std::logic_error &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
	} catch(const std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Main function to run the Span class tests.
 */
int	main( void ) {
    testSpan(5);
    testSpan(1);
    testSequence(10000);
    return 0;
}