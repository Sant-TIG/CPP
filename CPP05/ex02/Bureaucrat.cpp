/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:48:25 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:39:33 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
Bureaucrat::Bureaucrat( void ) : _name(), _grade() {
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
Bureaucrat::Bureaucrat( const std::string &name, int grade ) : _name(name), _grade(grade) {
	checkGrade(_grade);
	std::cout << GREEN << "Bureaucrat parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 * As the _name attribute is private, it need to be initialize to be copied.
 */
Bureaucrat::Bureaucrat( const Bureaucrat &oneBureaucrat ) : _name(oneBureaucrat._name) {
	*this = oneBureaucrat;
	std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator. As the _name attribute is private, it can't be
 * modified after initialize it.
 */
Bureaucrat & Bureaucrat::operator=( const Bureaucrat &oneBureaucrat ) {
	if (this != &oneBureaucrat) {
		_grade = oneBureaucrat._grade;
	}
	return *this;
}

/*
 * Destructor.
 */
Bureaucrat::~Bureaucrat( void ) {
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}

/*
 * Getter methods
 */
const std::string	Bureaucrat::getName( void ) const {
	return _name;
}

int	Bureaucrat::getGrade( void ) const {
	return _grade;
}

/*
 * Increments the bureaucrat's grade by 1 if it is possible. If the new grade is
 * larger than the highest grade throw a specific exception.
 */
void	Bureaucrat::incrementGrade( void ) {
	if (checkGrade(_grade - 1)) {
		_grade--;
	}
}

/*
 * Decrements the bureaucrat's grade by 1 if it is possible. If the new grade is
 * lower than the lowest grade throw a specific exception.
 */
void	Bureaucrat::decrementGrade( void ) {
	std::cout << _grade << std::endl;
	if (checkGrade(_grade + 1)) {
		_grade++;
	}
}

/*
 * Checks if the grade passed as a parameter is lower or larger than their respective
 * limits. In both cases, throws a specific exception.
 * Parameters:
 *     grade: value of the bureaucrat's grade
 * Return:
 *     true: if it is within the limits
 *     false: it is is not within the limits.
 */
bool	Bureaucrat::checkGrade( int grade ) const {
	if (grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	} else if (grade > LOWEST_GRADE ) {
		throw GradeTooLowException();
	} else {
		return true;
	}
	return false;
}

void	Bureaucrat::signForm( AForm &oneAForm ) {
	try {
		oneAForm.beSigned(*this);
		std::cout << _name << " signed " << oneAForm.getName() << std::endl;
	} catch (const AForm::GradeTooLowException &e) {
		std::cerr << _name << " couldn't sign " << oneAForm.getName() << " because " << e.what() << std::endl;
	}
}

/*
 * Overloads the insertion operator to display information about a bureaucrat.
 * Parameters:
 *     os: the output stream where the information will be displayed.
 *     oneBureaucrat: the object whose information is being displayed
 * Return:
 *     A reference to the output stream
 */
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &oneBureaucrat) {
	os << oneBureaucrat.getName() << ", bureaucrat grade " << oneBureaucrat.getGrade() << ".";
	return os;
}
