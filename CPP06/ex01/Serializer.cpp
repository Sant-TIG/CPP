/**
 * @file Serializer.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the Serializer class.
 * @date 2024-07-29
 * 
 * @details 
 */


#include "Serializer.hpp"

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new Serializer object with default values.
 */
Serializer::Serializer( void ) {
	std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Serializer object by copying the values from another object.
 *
 * @param otherSerializer A reference to the Serializer object to be copied.
 */
Serializer::Serializer( const Serializer &otherSerialize ) {
	*this = otherSerialize;
	std::cout << GREEN << "Serializer copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the Serializer object.
 */
Serializer::~Serializer( void ) {
	std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloaded assignment operator for Serializer class.
 * 
 * @param otherSerializer The source Serializer object to assign from.
 * @return Serializer& A reference to the current Serializer object after assignment.
 */
Serializer & Serializer::operator=( const Serializer &otherSerialize ) {
	if (this != &otherSerialize) {

	}
	return *this;
}


uintptr_t	Serializer::serialize( Data *ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize( uintptr_t raw ) {
	return (reinterpret_cast<Data *>(raw));
}