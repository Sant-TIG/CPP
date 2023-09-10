/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:06:37 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:15:03 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
WrongAnimal::WrongAnimal( void ) : _type("Wrong random animal") {
	std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
WrongAnimal::WrongAnimal( const std::string &type ) : _type(type) {
	std::cout << GREEN << "WrongAnimal parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
WrongAnimal::WrongAnimal( const WrongAnimal &oneWrongAnimal ) {
	*this = oneWrongAnimal;
	std::cout << GREEN << "WrongAnimal copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
WrongAnimal & WrongAnimal::operator=( const WrongAnimal &oneWrongAnimal ) {
	if (this != &oneWrongAnimal) {
		_type = oneWrongAnimal._type;
	}
	return *this;
}

/*
 * Destructor.
 */
WrongAnimal::~WrongAnimal( void ) {
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

/*
 * Getter methods
 */
std::string	WrongAnimal::getType( void ) const {
	return _type;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Wrong random animal sounds" << std::endl;
}
