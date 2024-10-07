/**
 * @file Intern.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the Inern class.
 * @date 2024-07-29
 * 
 * @details This file contains the implementation of the Intern class, including its 
 * constructors, destructors, assignment operators, and methods for creating 
 * forms based on given parameters.
 */

#include "Intern.hpp"

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new Intern object with default values.
 */
Intern::Intern( void ) {
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Intern object by copying the values from another object.
 *
 * @param otherIntern A reference to the Intern object to be copied.
 */
Intern::Intern( const Intern &otherIntern ) {
    *this = otherIntern;
	std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the Intern object.
 */
Intern::~Intern( void ) {
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloaded assignment operator for Intern class.
 * 
 * @param otherIntern The source Intern object to assign from.
 * @return Intern& A reference to the current Intern object after assignment.
 */
Intern & Intern::operator=( const Intern &otherIntern ) {
	if (this != &otherIntern) {
	}
	return *this;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Creates a ShrubberyCreationForm.
 * @param target The target for the form.
 * @return A pointer to the created ShrubberyCreationForm.
 */
static AForm    *createShrubberyForm( const std::string &target ) {
    return (new ShrubberyCreationForm(target));
}

/**
 * @brief Creates a RobotomyRequestForm.
 * @param target The target for the form.
 * @return A pointer to the created RobotomyRequestForm.
 */
static AForm    *createRobotomyForm( const std::string &target ) {
    return (new RobotomyRequestForm(target));
}

/**
 * @brief Creates a PresidentialPardonForm.
 * @param target The target for the form.
 * @return A pointer to the created PresidentialPardonForm.
 */
static AForm    *createPresidentialForm( const std::string &target ) {
    return (new PresidentialPardonForm(target));
}

/**
 * @brief Creates a form based on the given name and target.
 * 
 * This method checks the form name and returns a pointer to the created form object.
 *
 * @param name The name of the form to be created.
 * @param target The target associated with the form.
 * @return AForm* A pointer to the created form object, or NULL if the form name is invalid.
 */
AForm   *Intern::makeForm( const std::string &name, const std::string &target ) {
    const std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm   *(*formTypes[3])(const std::string &target) = {
        createShrubberyForm,
        createRobotomyForm,
        createPresidentialForm
    };

    for (int i = 0; i < 3; i++) {
        if (forms[i] == transformCase(name, "lower")) {
            std::cout << BLUE << "Intern creates " << forms[i] << RESET << std::endl;
            return formTypes[i](target);
        }
    }
    return NULL;
}

/**
 * @brief Transforms the case of a given string.
 * 
 * This function transforms all characters in the input string to either uppercase or lowercase 
 * based on the specified type. If an invalid type is provided, the original string is returned.
 * 
 * @param str The input string to be transformed.
 * @param type The type of transformation: "upper" for uppercase, "lower" for lowercase.
 * @return std::string The transformed string, or the original string if the type is invalid.
 */
std::string Intern::transformCase( const std::string &str, const std::string &type ) {
	std::string dst;
	std::size_t len = str.length();

	dst.reserve(len);
	const std::locale loc;
	if (type == "upper") {
		for (std::size_t i = 0; i < len; i++) {
			dst += std::toupper(str[i], loc);
		}		
	} else if (type == "lower") {
		for (std::size_t i = 0; i < len; i++) {
			dst += std::tolower(str[i], loc);
		}
	} else {
		return str;
	}
	return dst;
}