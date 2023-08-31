/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:50 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/31 14:27:51 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
 * Default constructor. Initializes instance variables
 */
HumanA::HumanA( const Weapon &oneWeapon ) : name(""), weapon((Weapon &)oneWeapon) {
	std::cout << GREEN << "HumanA default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
HumanA::HumanA( const std::string &name, const Weapon &oneWeapon ) : name(name), weapon((Weapon &)oneWeapon) {
	std::cout << GREEN << "HumanA parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
HumanA::HumanA( const HumanA &oneHumanA ) : name(oneHumanA.name), weapon(oneHumanA.weapon) {
	std::cout << GREEN << "HumanA copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
HumanA & HumanA::operator=( const HumanA &oneHumanA ) {
	if (this != &oneHumanA) {
		name = oneHumanA.name;
		weapon = oneHumanA.weapon;
	}
	return *this;
}

/*
 * Destructor.
 */
HumanA::~HumanA( void ) {
	std::cout << RED << "HumanA destructor called" << RESET << std::endl;
}

/*
 * Displays a message indicating that the HumanA is attacking with their weapon
 */
void	HumanA::attack( void ) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
