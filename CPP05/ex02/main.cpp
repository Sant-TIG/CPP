/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:47:06 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:39:45 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>

void	checkIncrement(Bureaucrat &one) {
	try {
		one.incrementGrade();
		std::cout << one << std::endl;
	} catch(const Bureaucrat::GradeTooHighException &e) {
		std::cerr << YELLOW << "Bureaucrat error: " << e.what() << RESET << std::endl;
	}
}

void	checkDecrement(Bureaucrat &one) {
	try {
		one.decrementGrade();
		std::cout << one << std::endl;
	} catch(const Bureaucrat::GradeTooLowException &e) {
		std::cerr << YELLOW << "Bureaucrat error: " << e.what() << RESET << std::endl;
	}
}

Bureaucrat createBureaucrat( const std::string &name, int grade ) {
	try {
		Bureaucrat	one(name, grade);
		return one;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << YELLOW << "Bureaucrat constructor error: " << e.what() << RESET << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << YELLOW << "Bureaucrat constructor error: " << e.what() << RESET << std::endl;
	}
	return Bureaucrat();
}

void    tryExecute(AForm &form, Bureaucrat &peter) {
    try {
		form.execute(peter);
	} catch (const AForm::GradeTooLowException &e) {
		std::cerr << YELLOW << "Form error: "  << e.what() << RESET << std::endl;
    }
}

int	main( void ) {
	PresidentialPardonForm	    veryImportant("Very important Form");
	RobotomyRequestForm			important("Important Form");
	ShrubberyCreationForm		notImportant("Not important form");
    ShrubberyCreationForm       notSigned("Not signed form");
	Bureaucrat peter = createBureaucrat("Peter", 75);
	Bureaucrat perkins = createBureaucrat("Perkins", 15);

	peter.signForm(veryImportant);
	peter.signForm(important);
	peter.signForm(notImportant);
	perkins.signForm(veryImportant);
	perkins.signForm(important);
	perkins.signForm(notImportant);

    tryExecute(veryImportant, peter);
    tryExecute(veryImportant, perkins);
    tryExecute(important, peter);
    tryExecute(important, perkins);
    tryExecute(notImportant, peter);
    tryExecute(notImportant, perkins);

    perkins.executeForm(notImportant);
    perkins.executeForm(important);
    perkins.executeForm(veryImportant);
    peter.executeForm(notImportant);
    peter.executeForm(important);
    peter.executeForm(veryImportant);
	notSigned.execute(perkins);

	return (0);
}
