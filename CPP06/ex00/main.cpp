#include <iostream>
#include "ScalarConversion.hpp"

int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << RED << "Bureaucrat default constructor called" << RESET << std::endl;		
	} else {
		ScalarConversion::convert(argv[1]);		
	}

}