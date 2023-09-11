/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:40:51 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:40:14 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/*
 * Default constructor. Initializes instance variables to 0.
 */
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm(), _target("") {
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ) : AForm(target, _signGrade, _execGrade), _target(target) {
	std::cout << GREEN << "ShrubberyCreationForm parameterized constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &oneShrubberyCreationForm ) : AForm(oneShrubberyCreationForm) {
	*this = oneShrubberyCreationForm;
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm &oneShrubberyCreationForm ) {
	if (this != &oneShrubberyCreationForm) {
		_target = oneShrubberyCreationForm._target;
	}
	return *this;
}

/*
 * Destructor.
 */
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

/*
 * Getter methods
 */
std::string	ShrubberyCreationForm::getTarget( void ) const {
	return _target;
}

/*
 *
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
