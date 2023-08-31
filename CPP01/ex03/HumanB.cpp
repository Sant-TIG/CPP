/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:59 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/31 14:28:02 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
 * Default constructor. Initializes instance variables to 0.
 */
HumanB::HumanB( void ) : name(""), weapon(NULL) {
	std::cout << GREEN << "HumanB default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructors. Initializes the instance variables with the values passed as parameters.
 */
HumanB::HumanB( const std::string &name ) : name(name), weapon(NULL) {
	std::cout << GREEN << name << " created" << RESET << std::endl;
}

HumanB::HumanB( const std::string &name, const Weapon &oneWeapon ) : name(name), weapon((Weapon *)&oneWeapon) {
	std::cout << GREEN << "HumanB parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
HumanB::HumanB( const HumanB &oneHuman ) {
	*this = oneHuman;
	std::cout << GREEN << "HumanA copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
HumanB & HumanB::operator=( const HumanB &oneHuman ) {
	if (this != &oneHuman) {
		name = oneHuman.name;
		weapon = oneHuman.weapon;
	}
	return *this;
}
/*
	Destructor
*/
HumanB::~HumanB( void ) {
	std::cout << RED << name << " destroyed" << RESET << std::endl;
}

/*
 * Displays a message indicating that the HumanA is attacking with their weapon
 */
void	HumanB::attack( void ) {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

/*
 * Setter methods
 */
void	HumanB::setWeapon( Weapon &oneWeapon ) {
	weapon = &oneWeapon;
}
