/**
 * @file RobotomyRequestForm.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the RobotomyRequestForm class.
 * @date 2024-07-29
 * 
 * @details This file contains the implementation of the RobotomyRequestForm class, 
 * which inherits from the AForm base class
 */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new RobotomyRequestForm object with default values.
 */
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm(), _target("") {
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new RobotomyRequestForm object with the values passed as parameters.
 * 
 * @param target The target for the robotomy request.
 */
RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm(target, _signGrade, _execGrade), _target(target) {
	std::cout << GREEN << "RobotomyRequestForm parameterized constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new RobotomyRequestForm object by copying the values from another object.
 *
 * @param otherRobotomyRequestForm A reference to the RobotomyRequestForm object to be copied.
 */
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &otherRobotomyRequestForm ) : AForm(otherRobotomyRequestForm) {
	*this = otherRobotomyRequestForm;
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the RobotomyRequestForm object.
 */
RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloaded assignment operator for RobotomyRequestForm class.
 * 
 * @param otherRobotomyRequestForm The source RobotomyRequestForm object to assign from.
 * @return RobotomyRequestForm& A reference to the current RobotomyRequestForm object after assignment.
 */
RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm &otherRobotomyRequestForm ) {
	if (this != &otherRobotomyRequestForm) {
		_target = otherRobotomyRequestForm._target;
	}
	return *this;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the target of the RobotomyRequestForm
 * 
 * @return const std::string& The target of the form.
 */
const std::string	&RobotomyRequestForm::getTarget( void ) const {
	return _target;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Executes the robotomy request on the target.
 * 
 * This method simulates a robotomy procedure by generating random success or failure
 * messages.
 */
void	RobotomyRequestForm::executeForm( void ) const {
    std::cout << BLUE << "* Bzzzzz... Vrrrrrr... Drill noises *" << RESET << std::endl;
    std::cout << BLUE << "Attempting robotomy on target: " << _target << RESET << std::endl;

    if (rand() % 2 == 0) {
        std::cout << BLUE << "Robotomy successful! " << _target << " has been robotomized." << RESET << std::endl;
    } else {
        std::cout << YELLOW << "Robotomy failed!" << RESET << std::endl;
    }
}
