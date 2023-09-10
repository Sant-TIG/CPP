/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:41:03 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 13:51:53 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
Animal::Animal( void ) : _type("Random Animal") {
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
Animal::Animal( const std::string &type ) : _type(type) {
	std::cout << GREEN << "Animal parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Animal::Animal( const Animal &oneAnimal ) {
	*this = oneAnimal;
	std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Animal & Animal::operator=( const Animal &oneAnimal ) {
	if (this != &oneAnimal) {
		_type = oneAnimal._type;
	}
	return *this;
}

/*
 * Destructor.
 */
Animal::~Animal( void ) {
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

/*
 * Getter methods
 */
std::string	Animal::getType( void ) const {
	return _type;
}

void	Animal::makeSound( void ) const {
	std::cout << "Random animal sounds" << std::endl;
}
