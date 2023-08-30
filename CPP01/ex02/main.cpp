#include <string>
#include <iostream>

/*
 * Program that illustrates the usage of pointers and references in C++.
 */
int	main( void ) {
	std::string		msg = "HI THIS IS BRAIN";
	std::string*	stringPTR = &msg;
	std::string&	stringREF = msg;

	std::cout << "Memory address of msg: " << &msg << std::endl;
	std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value of msg: " << msg << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}