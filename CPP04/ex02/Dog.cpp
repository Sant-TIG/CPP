/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:41:45 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:28:52 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
Dog::Dog( void ) : Animal("Dog"), _dogBrain(new Brain()) {
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Dog::Dog( const Dog &oneDog ) : Animal(oneDog), _dogBrain(new Brain()) {
	*this = oneDog;
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Dog & Dog::operator=( const Dog &oneDog ) {
	if (this != &oneDog) {
		_dogBrain = oneDog._dogBrain;
	}
	return *this;
}

/*
 * Destructor.
 */
Dog::~Dog( void ) {
	delete(_dogBrain);
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "Wof wof" << std::endl;
}
