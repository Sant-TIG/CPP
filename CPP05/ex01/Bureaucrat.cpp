/**
 * @file ShrubberyCreationForm.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the ShrubberyCreationForm class.
 * @date 2024-07-29
 * 
 * @details This file contains the implementation of the ShrubberyCreationForm class, 
 * which inherits from the AForm base class.
 */

#include "Bureaucrat.hpp"


/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new Bureaucrat object with default values.
 */
Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(LOWEST_GRADE) {
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Bureaucrat object with the values passed as parameters.
 *
 * @param name The name of the Bureaucrat.
 * @param grade The initial grade of the Bureaucrat.
 * @throw GradeTooHighException if the provided grade is too high.
 * @throw GradeTooLowException if the provided grade is too low.
 */
Bureaucrat::Bureaucrat( const std::string &name, unsigned int grade ) : _name(name), _grade(grade) {
	checkGrade(_grade);
	std::cout << GREEN << "Bureaucrat parameterized constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Bureaucrat object by copying the values from another object.
 *
 * @param otherBureaucrat A reference to the Bureaucrat object to be copied.
 */
Bureaucrat::Bureaucrat( const Bureaucrat &otherBureaucrat ) 
	: _name(otherBureaucrat.getName()), _grade(otherBureaucrat.getGrade()) {
	std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the Bureaucrat object.
 */
Bureaucrat::~Bureaucrat( void ) {
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the Bureaucrat class.
 *
 * @param otherBureaucrat The source Bureaucrat object to assign from.
 * @return Bureaucrat& A reference to the current Bureaucrat object after assignment.
 */
Bureaucrat & Bureaucrat::operator=( const Bureaucrat &otherBureaucrat ) {
	if (this != &otherBureaucrat) {
		_grade = otherBureaucrat.getGrade();
	}
	return *this;
}

/**
 * @brief Overloads the stream insertion operator for the Bureaucrat class
 * to be easily printed to an output stream.
 *
 * @param os The output stream.
 * @param otherBureaucrat The Bureaucrat object to be printed.
 * @return std::ostream& A reference to the output stream.
 */
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &otherBureaucrat) {
	os << otherBureaucrat.getName() << ", bureaucrat grade " << otherBureaucrat.getGrade() << ".";
	return os;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the name of the Bureaucrat
 * 
 * @return const std::string& The name of the Bureaucrat.
 */
const std::string	&Bureaucrat::getName( void ) const {
	return _name;
}

/**
 * @brief Retrieves the grade of the Bureaucrat
 * 
 * @return const unsigned int& The grade of the Bureaucrat.
 */
const unsigned int	&Bureaucrat::getGrade( void ) const {
	return _grade;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Decreases the Bureaucrat's grade by one, making sure it doesn't exceed the highest grade.
 * 
 * @throw GradeTooHighException if the grade exceeds the highest allowed grade.
 */
void	Bureaucrat::incrementGrade( void ) {
	if (checkGrade(_grade - 1)) {
		_grade--;
	}
}

/**
 * @brief Increases the Bureaucrat's grade by one, making sure it doesn't fall below the lowest grade.
 * 
 * @throw GradeTooLowException if the grade falls below the lowest allowed grade.
 */
void	Bureaucrat::decrementGrade( void ) {
	if (checkGrade(_grade + 1)) {
		_grade++;
	}
}

/**
 * @brief Validates that the grade is within the allowed range, throwing exceptions if it is not.
 * 
 * @param grade The grade to be checked.
 * @return true If the grade is valid.
 * @return false If the grade is not valid, although the method primarily uses exceptions for error handling.
 * @throw GradeTooHighException if the grade is higher than the allowed maximum.
 * @throw GradeTooLowException if the grade is lower than the allowed minimum.
 */
bool	Bureaucrat::checkGrade( unsigned int grade ) const {
	if (grade < HIGHEST_GRADE) {
		throw GradeTooHighException();
	} else if (grade > LOWEST_GRADE ) {
		throw GradeTooLowException();
	} else {
		return true;
	}
	return false;
}

/**
 * @brief Attempts to sign a form, checking if the bureaucrat's grade is sufficient.
 *
 * @param oneForm The form to be signed.
 */
void	Bureaucrat::signForm( Form &oneForm ) {
	try {
		oneForm.beSigned(*this);
		std::cout << BLUE << _name << " signed " << oneForm.getName() << RESET << std::endl;
	} catch (const Form::GradeTooLowException &e) {
		std::cerr << YELLOW << _name << " couldn't sign " << oneForm.getName() << " because " << e.what() << RESET << std::endl;
	}
}