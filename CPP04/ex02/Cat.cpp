/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:41:28 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:28:41 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
Cat::Cat( void ) : Animal("Cat"), _catBrain(new Brain()) {
	std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Cat::Cat( const Cat &oneCat ) : Animal(oneCat), _catBrain(new Brain()) {
	*this = oneCat;
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Cat & Cat::operator=( const Cat &oneCat ) {
	if (this != &oneCat) {
		_catBrain = oneCat._catBrain;
	}
	return *this;
}

/*
 * Destructor.
 */
Cat::~Cat( void ) {
	delete(_catBrain);
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "Miiaaauuuuu..." << std::endl;
}
