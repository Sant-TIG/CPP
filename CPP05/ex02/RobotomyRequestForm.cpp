/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:41:15 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:40:07 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

/*
 * Default constructor. Initializes instance variables to 0.
 */
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm(), _target() {
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm(target, _signGrade, _execGrade), _target(target) {
	std::cout << GREEN << "RobotomyRequestForm parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &oneRobotomyRequestForm ) : AForm(oneRobotomyRequestForm) {
	*this = oneRobotomyRequestForm;
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm &oneRobotomyRequestForm ) {
	if (this != &oneRobotomyRequestForm) {
		_target = oneRobotomyRequestForm._target;
	}
	return *this;
}

/*
 * Destructor.
 */
RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

/*
 * Getter methods
 */
std::string	RobotomyRequestForm::getTarget( void ) const {
	return _target;
}

/*
 *
 */
void	RobotomyRequestForm::executeForm( void ) const {
    std::cout << "* Bzzzzz... Vrrrrrr... Drill noises *" << std::endl;
    std::cout << "Attempting robotomy on target: " << _target << std::endl;

    if (rand() % 2 == 0) {
        std::cout << "Robotomy successful! " << _target << " has been robotomized." << std::endl;
    } else {
        std::cout << "Robotomy failed!" << std::endl;
    }
}
