/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:06:51 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:15:16 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
WrongCat::WrongCat( void ) : WrongAnimal("Wrong cat") {
	std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
WrongCat::WrongCat( const WrongCat &oneWrongCat ) : WrongAnimal(oneWrongCat) {
	*this = oneWrongCat;
	std::cout << GREEN << "WrongCat copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
WrongCat & WrongCat::operator=( const WrongCat &oneWrongCat ) {
	if (this != &oneWrongCat) {
	}
	return *this;
}

/*
 * Destructor.
 */
WrongCat::~WrongCat( void ) {
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "Wrong miiaaauuuuu..." << std::endl;
}
