/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:41:28 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 13:52:07 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
Cat::Cat( void ) : Animal("Cat") {
	std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Cat::Cat( const Cat &oneCat ) : Animal(oneCat) {
	*this = oneCat;
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Cat & Cat::operator=( const Cat &oneCat ) {
	if (this != &oneCat) {
	}
	return *this;
}

/*
 * Destructor.
 */
Cat::~Cat( void ) {
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "Miiaaauuuuu..." << std::endl;
}
