/**
 * @file utils.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the Base class 
 * @date 2024-07-29
 */
#include "Base.hpp"

/**
 * @brief Destroy the Base object.
 */
Base::~Base( void ) {
	std::cout << RED << "Base destructor called" << RESET << std::endl;
}