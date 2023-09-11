/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:48:07 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:39:50 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
PresidentialPardonForm::PresidentialPardonForm( void ) : AForm(), _target("") {
	std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
PresidentialPardonForm::PresidentialPardonForm( const std::string &target ) : AForm(target, _signGrade, _execGrade), _target(target) {
	std::cout << GREEN << "PresidentialPardonForm parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &onePresidentialPardonForm ) : AForm(onePresidentialPardonForm) {
	*this = onePresidentialPardonForm;
	std::cout << GREEN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm &onePresidentialPardonForm ) {
	if (this != &onePresidentialPardonForm) {
		_target = onePresidentialPardonForm._target;
	}
	return *this;
}

/*
 * Destructor.
 */
PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

std::string	PresidentialPardonForm::getTarget( void ) const {
	return _target;
}

void	PresidentialPardonForm::executeForm( void ) const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
