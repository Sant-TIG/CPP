/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:41:49 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:41:50 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name) {
	health = 100;
	energy = 50;
	damage = 20;
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
ScavTrap::ScavTrap( const ScavTrap &oneScavTrap ) : ClapTrap(oneScavTrap) {
	*this = oneScavTrap;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
ScavTrap & ScavTrap::operator=( const ScavTrap &oneScavTrap ) {
	if (this != &oneScavTrap) {
		name = oneScavTrap.name;
		health = oneScavTrap.health;
		energy = oneScavTrap.energy;
		damage = oneScavTrap.damage;
	}
	return *this;
}

/*
 * Destructor.
 */
ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
