/**
 * @file AForm.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the AForm class.
 * @date 2024-07-29
 * 
 * @details This file contains the implementation of the AForm class methods. 
 * The AForm class provides the core functionality for managing the signing and 
 * execution process of a form, as well as handling exceptions for grade constraints.
 */

#include "AForm.hpp"
#include <iostream>


/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new AForm object with default values.
 */
AForm::AForm( void ) : _name(), _signGrade(), _execGrade(), _signed(false) {
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new AForm object with the values passed as parameters.
 *
 * @param name Name of the form.
 * @param signGrade The grade required to sign the form.
 * @param execGrade The grade required to execute the form.
 */
AForm::AForm( const std::string &name, const unsigned int signGrade, const unsigned int execGrade )
			: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
	std::cout << GREEN << "AForm parameterized constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new AForm object by copying the values from another object.
 *
 * @param otherAForm A reference to the AForm object to be copied.
 */
AForm::AForm( const AForm &otherAForm ) : _name(otherAForm._name), _signGrade(otherAForm._signGrade), _execGrade(otherAForm._execGrade) {
	*this = otherAForm;
	std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the AForm object.
 */
AForm::~AForm( void ) {
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the AForm class.
 *
 * @param otherAForm The source AForm object to assign from.
 * @return AForm& A reference to the current AForm object after assignment.
 */
AForm & AForm::operator=( const AForm &otherAForm ) {
	if (this != &otherAForm) {
		_signed = otherAForm._signed;
	}
	return *this;
}

/**
 * @brief Overloads the stream insertion operator for the AForm class
 * to be easily printed to an output stream.
 *
 * @param os The output stream.
 * @param otherForm The AForm object to be printed.
 * @return std::ostream& A reference to the output stream.
 */
std::ostream	&operator<<( std::ostream &os, const AForm &otherAForm ) {
	os << otherAForm.getName();
	return os;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the name of the AForm
 * 
 * @return const std::string& The name of the AForm.
 */
const std::string	&AForm::getName( void ) const {
	return _name;
}

/**
 * @brief Retrieves the sign grade of the AForm
 * 
 * @return unsigned int The sign grade of the AForm.
 */
unsigned int	AForm::getSignGrade( void ) const {
	return _signGrade;
}

/**
 * @brief Retrieves the execution grade of the AForm
 * 
 * @return unsigned int The execution grade of the AForm.
 */
unsigned int	AForm::getExecGrade( void ) const {
	return _execGrade;
}

/**
 * @brief Retrieves the signed status of the AForm
 * 
 * @return bool The signed status of the AForm.
 */
bool	AForm::getSigned( void ) const {
	return _signed;
}


/* ------------ SETTER METHODS ------------ */

/**
 * @brief Sets the signed status of the AForm
 */
void	AForm::setSigned( bool sign ) {
	_signed = sign;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Allow a Bureaucrat to sign the form if his sign grade is high enough.
 * 
 * @param bureaucrat The Bureaucrat attempting to sign the form.
 */
void	AForm::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() <= _signGrade) {
		_signed = true;
	} else {
		throw GradeTooLowException();
	}
}

/**
 * @brief Executes the form if the requirements are met.
 * 
 * @param executor The Bureaucrat executing the form.
 * 
 * If the form is signed and the executor's grade is high enough, the form is executed. 
 * Otherwise, an exception is thrown or an error message is displayed.
 */
void	AForm::execute( const Bureaucrat &executor ) const {
	if (_signed == true) {
		if (executor.getGrade() <= _execGrade) {
			executeForm();
		} else {
			throw GradeTooLowException();
		}
	} else {
		std::cout << RED << "The form is not signed" << RESET << std::endl;
	}
}


