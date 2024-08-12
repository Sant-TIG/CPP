/**
 * @file main.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Entry point of the program for evaluating Reverse Polish Notation (RPN) expressions.
 * @date 2024-07-29
 */

#include "RPN.hpp"
#include "Colors.hpp"

/**
 * @brief Entry point of the program for evaluating Reverse Polish Notation (RPN) expressions.
 *
 * @param argc The number of command line arguments.
 * @param argv The array of command-line arguments.
 *
 * @return int Returns 0 on success, 1 if the number of arguments is incorrect, and 2 if an evaluation error occurs.
 */
int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << RED << "Error: invalid number of arguments.\n" << YELLOW << "Usage: ./RPN <inverted Polish mathematical expression in string format>" << RESET << std::endl;
		return 1;
	}
	try {
		RPN::evaluateExpression(argv[1]);
	} catch(const RPN::StackError &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 2;
	}
	return 0;
}