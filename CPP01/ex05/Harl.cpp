/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:30:00 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/31 14:44:11 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

/*
 * Definition of the static variable LEVELS.
 */
const std::string Harl::LEVELS[NBR_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

/*
 * Default constructor. Initializes instance variables to 0.
 */
Harl::Harl( void ) {
	std::cout << "Harl default constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Harl::Harl( const Harl &oneHarl ) {
	*this = oneHarl;
	std::cout << "Harl copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Harl & Harl::operator=( const Harl &oneHarl ) {
	if (this != &oneHarl) {
		
	}
	return *this;
}

/*
 * Destructor.
 */
Harl::~Harl( void ) {
	std::cout << "Harl destructor called" << std::endl;
}

/*
 * Complain methods.
 */
void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


/*
 * Displays the message corresponding to the complaint level passed as a parameter.
 * Parameters:
 *     level: the level of the complaint message
 */
void	Harl::complain( const std::string &level ) {
	void (Harl::*methodPtr[NBR_LEVELS])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	int	index = getLevelIndex(level);
	if (index != -1) {
		(this->*methodPtr[index])();
	} else {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

/*
 * Checks if the level passed as a parameter is valid. If it is, it returns its index.
 * Parameters:
 *     level: the level of the complaint message
 * Return:
 *     index: the index of the level
 */
int	Harl::getLevelIndex( const std::string &level ) {
	int index = -1;
	for (int i = 0; i < NBR_LEVELS; i++)
	{
		if (level == LEVELS[i])
		{
			index = i;
			return index;
		}
	}
	return index;
}
