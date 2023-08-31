/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:28:13 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/31 14:28:15 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include "Colors.hpp"

/*
 * Default constructor. Initializes instance variables to 0.
 */
Weapon::Weapon( void ) : type("") {
	std::cout << GREEN << "Weapon default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
Weapon::Weapon( const std::string &oneType ) : type(oneType) {
	std::cout << GREEN << "Weapon: " << this->type << " created" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Weapon::Weapon( const Weapon &oneWeapon ) : type(oneWeapon.type) {
	std::cout << GREEN << "Weapon copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Weapon & Weapon::operator=( const Weapon &oneWeapon ) {
	if (this != &oneWeapon) {
		type = oneWeapon.type;
	}
	return *this;
}

/*
 * Destructor.
 */
Weapon::~Weapon( void ) {
	std::cout << RED << type << " destroyed" << RESET << std::endl;
}

/*
 * Getter methods
 */
const std::string&	Weapon::getType( void ) {
	return type;
}

/*
 * Setter methods
 */
void	Weapon::setType( const std::string &otherType ) {
	type = otherType;
}
