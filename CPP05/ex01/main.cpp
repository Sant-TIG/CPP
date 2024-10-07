/**
 * @file main.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Entry point for the Bureaucrat and Form interaction program.
 * 
 * @details This program demonstrates the interaction between Bureaucrat and Form classes, where Bureaucrats
 * attempt to sign forms based on their grade, and exceptions are handled for invalid grade ranges.
 * 
 * @date 2024-08-13
 */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * @brief Creates a Bureaucrat object with the specified name and grade.
 * 
 * @param name The name of the Bureaucrat to create.
 * @param grade The grade to assign to the Bureaucrat.
 * 
 * @return Bureaucrat A Bureaucrat object with the specified name and grade, or a default Bureaucrat in case of an error.
 * 
 * @throws Bureaucrat::GradeTooHighException if the grade is higher than allowed.
 * @throws Bureaucrat::GradeTooLowException if the grade is lower than allowed.
 */
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


int	main( void ) {
	Form		veryImportant("Very important Form", 10, 2, false);
	Form		important("Important Form", 45, 10, false);
	Form		notImportant("Not important form", 100, 60, false);
	Bureaucrat peter = createBureaucrat("Peter", 75);
	Bureaucrat perkins = createBureaucrat("Perkins", 15);
	peter.signForm(veryImportant);
	peter.signForm(important);
	peter.signForm(notImportant);
	perkins.signForm(veryImportant);
	perkins.signForm(important);
	perkins.signForm(notImportant);
	return (0);
}
