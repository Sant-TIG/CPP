/**
 * @file utils.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of functions to identify derived classes from the Base class and to create 
 * random instances of derived classes.
 * @date 2024-07-29
 * 
 * @details This file contains two overloaded `identify` functions, one taking a pointer and the other 
 * a reference, to dynamically identify and print the derived class type (A, B, or C) 
 * from a polymorphic base class pointer or reference. The identification is done using 
 * C++'s `dynamic_cast` for safe runtime type casting. It also contains the `generate` function, 
 * which randomly instantiates and returns a pointer to one of the derived classes (A, B, or C) 
 * from the Base class.
 */

#include "utils.hpp"


/**
 * @brief Identifies the derived class type from a Base pointer.
 * 
 * This function checks if the provided Base pointer `p` points to an object of type A, B, 
 * or C.
 * 
 * @param p A pointer to the Base class or its derivatives.
 */
void	identify( Base *p ) {
	if (dynamic_cast<A *>(p)) {
		std::cout << 'A' << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << 'B' << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << 'C' << std::endl;
	} else {
		std::cout << "NULL" << std::endl;
	}
}

/**
 * @brief Identifies the derived class type from a Base reference.
 * 
 * This function operates similarly to the pointer-based version, but it uses references 
 * and C++'s `dynamic_cast` with `try-catch` blocks to handle the case where the cast fails. 
 * 
 * @param p A reference to the Base class or its derivatives.
 */
void	identify( Base &p ) {
	try {
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << 'A' << std::endl;
	} catch( const std::exception &ec ) {}
	try {
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << 'B' << std::endl;
	} catch( const std::exception &ec ) {}
	try {
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << 'C' << std::endl;
	} catch( const std::exception &ec ) {}
}

/**
 * @brief Randomly generates an instance of a derived class from Base.
 * @return Base* A pointer to a newly created instance of A, B, or C.
 */
Base * generate( void ) {
	std::srand(std::time(NULL));
	switch (rand() % 3) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return NULL;
	}
}