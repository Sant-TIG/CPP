/**
 * @file Form.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the Form class for handling bureaucratic forms with specific sign and execution grades.
 * This class represents a form that can be signed and executed by Bureaucrats. It enforces strict rules
 * regarding who can sign or execute a form based on their grade.
 * @date 2024-07-29
 */

#include "Form.hpp"

class Bureaucrat;

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new Form object with default values.
 */
Form::Form( void ) : _name(), _signGrade(), _execGrade(), _signed(false) {
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Form object with the values passed as parameters.
 * 
 * @param name The name of the form.
 * @param signGrade The grade required to sign the form.
 * @param execGrade The grade required to execute the form.
 * @param isSigned Boolean indicating if the form has been signed.
 */
Form::Form( const std::string &name, const int signGrade, const int execGrade, bool isSigned )
			: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(isSigned) {
	std::cout << GREEN << "Form parameterized constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Form object by copying the values from another Form object.
 *
 * @param otherForm A reference to the Form object to copy.
 */
Form::Form( const Form &otherForm ) : _name(otherForm._name), _signGrade(otherForm._signGrade), _execGrade(otherForm._execGrade), _signed(otherForm._signed) {
	*this = otherForm;
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the Form object.
 */
Form::~Form( void ) {
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the Form class.
 *
 * @param otherForm A reference to the Form object to assign from.
 * @return Form& A reference to the assigned Form object (self).
 */
Form & Form::operator=( const Form &otherForm ) {
	if (this != &otherForm) {
		_signed = otherForm._signed;
	}
	return *this;
}

/**
 * @brief Overloads the stream insertion operator for the Form class
 * to be easily printed to an output stream.
 *
 * @param os The output stream.
 * @param otherForm The Form object to be printed.
 * @return std::ostream& A reference to the output stream.
 */
std::ostream	&operator<<( std::ostream &os, const Form &otherForm ) {
	os << otherForm.getName();
	return os;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the name of the form.
 * 
 * @return A constant reference to the form's name.
 */
const std::string	&Form::getName( void ) const {
	return _name;
}

/**
 * @brief Retrieves the grade required to sign the form.
 * 
 * @return A constant reference to the sign grade of the form.
 */
const unsigned int	&Form::getSignGrade( void ) const {
	return _signGrade;
}

/**
 * @brief Retrieves the grade required to execute the form.
 * 
 * @return A constant reference to the execution grade of the form.
 */
const unsigned int	&Form::getExecGrade( void ) const {
	return _execGrade;
}

/**
 * @brief Checks if the form has been signed.
 * 
 * @return A boolean indicating whether the form is signed (true) or not (false).
 */
bool	Form::getSigned( void ) const {
	return _signed;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Allows a Bureaucrat to sign the form if their grade is high enough.
 * 
 * @param bureaucrat A reference to the Bureaucrat attempting to sign the form.
 * 
 * @throws GradeTooLowException if the Bureaucrat's grade is too low to sign the form.
 */
void	Form::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() <= _signGrade) {
		_signed = true;
	} else {
		throw GradeTooLowException();
	}
}


