/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:28:24 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:28:26 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
Brain::Brain( void ) {
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Brain::Brain( const Brain &oneBrain ) {
	*this = oneBrain;
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Brain & Brain::operator=( const Brain &oneBrain ) {
	if (this != &oneBrain) {

	}
	return *this;
}

/*
 * Destructor.
 */
Brain::~Brain( void ) {
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
}
