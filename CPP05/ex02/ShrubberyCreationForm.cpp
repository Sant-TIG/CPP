/**
 * @file ShrubberyCreationForm.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the ShrubberyCreationForm class.
 * @date 2024-07-29
 * 
 * @details This file contains the implementation of the ShrubberyCreationForm class, 
 * which inherits from the AForm base class.
 */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new ShrubberyCreationForm object with default values.
 */
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm(), _target("") {
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new ShrubberyCreationForm object with the values passed as parameters.
 * 
 * @param target The target for the shrubbery creation form.
 */
ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ) : AForm(target, _signGrade, _execGrade), _target(target) {
	std::cout << GREEN << "ShrubberyCreationForm parameterized constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new ShrubberyCreationForm object by copying the values from another object.
 *
 * @param otherShrubberyCreationForm A reference to the ShrubberyCreationForm object to be copied.
 */
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &otherShrubberyCreationForm ) : AForm(otherShrubberyCreationForm), _target(otherShrubberyCreationForm._target) {
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the ShrubberyCreationForm object.
 */
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloaded assignment operator for ShrubberyCreationForm class.
 * 
 * @param otherShrubberyCreationForm The source ShrubberyCreationForm object to assign from.
 * @return ShrubberyCreationForm& A reference to the current ShrubberyCreationForm object after assignment.
 */
ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm &otherShrubberyCreationForm ) {
	if (this != &otherShrubberyCreationForm) {
		_target = otherShrubberyCreationForm._target;
	}
	return *this;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the target of the ShrubberyCreationForm
 * 
 * @return const std::string& The target of the form.
 */
const std::string	&ShrubberyCreationForm::getTarget( void ) const {
	return _target;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Executes the shrubbery creation form.
 */
void	ShrubberyCreationForm::executeForm( void ) const {
	std::string	fileName = _target + "_shrubbery";
	std::ofstream shruberyFile(fileName.c_str());
	if (!shruberyFile) {
		std::cerr << "Error opening the file for shruberry creation: " << fileName << std::endl;
		return;
	}
	shruberyFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	shruberyFile << "    ,&&%&%&&%,@@@@@/@@@@@@,8888888/8o" << std::endl;
	shruberyFile << "   ,%&&&&&%&&%,@@@@@@@/@@@88888888/88'" << std::endl;
	shruberyFile << "   %&&%&%&/%&&%@@@@@/ /@@@88888888888'" << std::endl;
	shruberyFile << "   %&&%/ %&@%&&@@ @ V /@@' `8888 `/88'" << std::endl;
	shruberyFile << "   `&%& ` /%&'    |.|        8 '|8'" << std::endl;
	shruberyFile << "       |o|        | |         | |" << std::endl;
	shruberyFile << "       |.|        | |         | |" << std::endl;
	shruberyFile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
}
