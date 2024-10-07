/**
 * @file PresidentialPardonForm.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the PresidentialPardonForm class.
 * @date 2024-07-29
 * 
 * @details This file contains the implementation of the PresidentialPardonForm class, 
 * which inherits from the AForm base class.
 */

#include "PresidentialPardonForm.hpp"
#include <iostream>

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new PresidentialPardonForm object with default values.
 */
PresidentialPardonForm::PresidentialPardonForm( void ) : AForm(), _target("") {
	std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new PresidentialPardonForm object with the values passed as parameters.
 * 
 * @param target The target for the presidential pardon request.
 */
PresidentialPardonForm::PresidentialPardonForm( const std::string &target ) : AForm(target, _signGrade, _execGrade), _target(target) {
	std::cout << GREEN << "PresidentialPardonForm parameterized constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new PresidentialPardonForm object by copying the values from another object.
 *
 * @param otherPresidentialPardonForm A reference to the PresidentialPardonForm object to be copied.
 */
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &otherPresidentialPardonForm ) : AForm(otherPresidentialPardonForm) {
	*this = otherPresidentialPardonForm;
	std::cout << GREEN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the PresidentialPardonForm object.
 */
PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloaded assignment operator for PresidentialPardonForm class.
 * 
 * @param otherPresidentialPardonForm The source PresidentialPardonForm object to assign from.
 * @return PresidentialPardonForm& A reference to the current PresidentialPardonForm object after assignment.
 */
PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm &otherPresidentialPardonForm ) {
	if (this != &otherPresidentialPardonForm) {
		_target = otherPresidentialPardonForm._target;
	}
	return *this;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the target of the PresidentialPardonForm
 * 
 * @return const std::string& The target of the form.
 */
const std::string	&PresidentialPardonForm::getTarget( void ) const {
	return _target;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Executes the presidential pardon form.
 */
void	PresidentialPardonForm::executeForm( void ) const {
	std::cout << BLUE << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
