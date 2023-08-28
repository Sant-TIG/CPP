#include "Zombie.hpp"
#include <cstdlib>
#include <sstream>

int	processArgs( int argc, char **argv );
int	checkIntArgs( int argc, char **argv, int *num );
int	typeErrorMsg( void );

/*
 * Main function of the program. Parses command-line arguments and creates/deletes a zombie horde accordingly.
 * Parameters:
 *     argc: number of command-line arguments
 *     argv: array of pointers to command-line argument strings
 * Return:
 *     0: if the program execution was successful
 *     1: if there was an error during argument processing.
 */
int	main( int argc, char **argv ) {
	if (processArgs(argc, argv) == 1) {
		return 1;
	} else {
		Zombie*	zombies = zombieHorde(std::atoi(argv[1]), "Quino");
		delete [] zombies;
	}
	return 0;
}

/*
 * Processes and validates command-line arguments for the program.
 * Ensures that a single positive integer argument is provided.
 * Parameters:
 *     argc: number of command-line arguments
 *     argv: arrays of pointers to command-line argument strings
 * Return:
 *     0: if the arguments are succesfully validated
 *     1: if there is an error in the argument count, type, or range
 */
int	processArgs( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << "zombieHorde: error: invalid number of arguments" << std::endl;
		std::cout << "Usage: ./zombieHorde <positive integer>" << std::endl;
		return 1;
	} else {
		int	num;
		if (checkIntArgs( argc, argv, &num) == 1) {
			return 1;
		}
		if (num < 0) {
			return typeErrorMsg();
		}
	}
	return 0;
}

/*
 * Validates the provided command-line argument as a positive integer.
 * Parameters:
 *     argc: number of command-line arguments
 *     argv: arrays of pointers to command-line argument strings
 *     num: pointer to store the validated integer value
 * Return:
 *     0: if the argument is succesfully validated
 *     1: if there is an error in the argument type or format
 */
int	checkIntArgs( int argc, char **argv, int *num ) {
	for (int i = 1; i < argc; i++) {
		std::istringstream	iss(argv[i]);
		char	remainingChar;
		if (iss >> *num) {
			if (iss.get(remainingChar)) {
				return typeErrorMsg();
			}
			return 0;
		} else {
			return typeErrorMsg();
		}
	}
	return 0;
}

/*
 * Displays an error message for an invalid argument type.
 * Provides usage instructions for the program.
 * Return:
 *     1: to indicate an error occurred
 */
int	typeErrorMsg( void ) {
	std::cout << "zombieHorde: error: invalid type of argument." << std::endl;
	std::cout << "Usage: ./zombieHorde <positive integer>" << std::endl;
	return 1;
}