/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:32:52 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 16:32:53 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * Default constructor. Initializes instance variables to 0.
 */
Zombie::Zombie( void ) {
	std::cout << "Zombie default constructor called" << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
Zombie::Zombie( const std::string &name ) : name(name) {
	std::cout << "Zombie parameterized constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Zombie::Zombie( const Zombie &oneZombie ) {
	*this = oneZombie;
	std::cout << "Zombie copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Zombie & Zombie::operator=( const Zombie &oneZombie ) {
	if (this != &oneZombie) {
		name = oneZombie.name;
	}
	return *this;
}

/*
 * Destructor
 */
Zombie::~Zombie( void ) {
	std::cout << "Zombie destructor called" << std::endl;
}

/*
 * Getter methods
 */
std::string	Zombie::getName( void ) {
	return name;
}

/*
 * Announces the presence of the zombie by printing a message to the console.
 */
void	Zombie::announce( void ) {
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
