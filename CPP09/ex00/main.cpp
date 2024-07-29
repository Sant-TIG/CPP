/**
 * @file main.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Main function of the BitcoinExchange program.
 * @date 2024-07-25
 */

#include "BitcoinExchange.hpp"

/**
 * @brief Main function of the BitcoinExchange program.
 *
 * It expects one command-line argument specifying the name of the input file.
 * It creates an instance of BitcoinExchange and calls the showExchange method
 * to process the file.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return int Returns 0 on success, 1 if the number of arguments is incorrect,
 *             and 2 if a DBError is caught during execution.
 */
int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << "Error: invalid number of arguments.\nUsage: ./btc file_name.txt" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc;
		btc.showExchange(argv[1]);
	} catch(const BitcoinExchange::DBError &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 2;
	}
	return 0;

}