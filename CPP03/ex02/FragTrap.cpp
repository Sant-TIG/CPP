/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:45:42 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:46:39 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	health = 100;
	energy = 100;
	damage = 30;
	std::cout << "FragTrap parameterized constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
FragTrap::FragTrap( const FragTrap &oneFragTrap ) : ClapTrap(oneFragTrap) {
	*this = oneFragTrap;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
FragTrap & FragTrap::operator=( const FragTrap &oneFragTrap ) {
	if (this != &oneFragTrap) {
		name = oneFragTrap.name;
		health = oneFragTrap.health;
		energy = oneFragTrap.energy;
		damage = oneFragTrap.damage;
	}
	return *this;
}

/*
 * Destructor.
 */
FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << name << " says: Give me five!" << std::endl;
}
