/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:33:32 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 15:05:55 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
Form::Form( void ) : _name(), _signGrade(), _execGrade(), _signed(false) {
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
Form::Form( const std::string &name, const int signGrade, const int execGrade )
			: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
	std::cout << GREEN << "Form parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Form::Form( const Form &oneForm ) : _name(oneForm._name), _signGrade(oneForm._signGrade), _execGrade(oneForm._execGrade) {
	*this = oneForm;
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Form & Form::operator=( const Form &oneForm ) {
	if (this != &oneForm) {
		_signed = oneForm._signed;
	}
	return *this;
}

/*
 * Destructor.
 */
Form::~Form( void ) {
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}

/*
 * Getter methods
 */
const std::string	Form::getName( void ) const {
	return _name;
}

int	Form::getSignGrade( void ) const {
	return _signGrade;
}

int	Form::getExecGrade( void ) const {
	return _execGrade;
}

bool	Form::getSigned( void ) const {
	return _signed;
}

/*
 *
 */
void	Form::beSigned( const Bureaucrat &peter ) {
	if (peter.getGrade() <= _signGrade) {
		_signed = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream	&operator<<( std::ostream &os, const Form &oneForm ) {
	os << oneForm.getName();
	return os;
}

