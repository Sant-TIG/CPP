/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:33:32 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:39:22 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
AForm::AForm( void ) : _name(), _signGrade(), _execGrade(), _signed(false) {
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
AForm::AForm( const std::string &name, const int signGrade, const int execGrade )
			: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
	std::cout << GREEN << "AForm parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
AForm::AForm( const AForm &oneAForm ) : _name(oneAForm._name), _signGrade(oneAForm._signGrade), _execGrade(oneAForm._execGrade) {
	*this = oneAForm;
	std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
AForm & AForm::operator=( const AForm &oneAForm ) {
	if (this != &oneAForm) {
		_signed = oneAForm._signed;
	}
	return *this;
}

/*
 * Destructor.
 */
AForm::~AForm( void ) {
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

/*
 * Getter methods
 */
const std::string	AForm::getName( void ) const {
	return _name;
}

int	AForm::getSignGrade( void ) const {
	return _signGrade;
}

int	AForm::getExecGrade( void ) const {
	return _execGrade;
}

bool	AForm::getSigned( void ) const {
	return _signed;
}

void	AForm::setSigned( bool sign ) {
	_signed = sign;
}

/*
 *
 */
void	AForm::beSigned( const Bureaucrat &peter ) {
	if (peter.getGrade() <= _signGrade) {
		_signed = true;
	} else {
		throw GradeTooLowException();
	}
}

void	AForm::execute( const Bureaucrat &executor ) const {
	if (_signed == true) {
		if (executor.getGrade() <= _execGrade) {
			executeForm();
		} else {
			throw GradeTooLowException();
		}
	} else {
		std::cout << "The form is not signed" << std::endl;
	}
}

std::ostream	&operator<<( std::ostream &os, const AForm &oneAForm ) {
	os << oneAForm.getName();
	return os;
}

