/**
 * @file main.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Entry point for testing the Bureaucrat class functionality.
 * 
 * This program demonstrates the creation of Bureaucrat objects and the handling 
 * of exceptions when creating an object or incrementing and decrementing their grades.
 * 
 * @date 2024-08-13
 */

#include "Bureaucrat.hpp"

/**
 * @brief Attempts to increment the grade of a Bureaucrat object and handles exceptions.
 * 
 * @param one A reference to the Bureaucrat object whose grade is to be incremented.
 */
void	checkIncrement( Bureaucrat &one ) {
	try {
		one.incrementGrade();
		std::cout << BLUE << one << RESET << std::endl;
	} catch(const Bureaucrat::GradeTooHighException &e) {
		std::cerr << YELLOW << "Increment error: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Attempts to decrement the grade of a Bureaucrat object and handles exceptions.
 * 
 * @param one A reference to the Bureaucrat object whose grade is to be decremented.
 */
void	checkDecrement( Bureaucrat &one ) {
	try {
		one.decrementGrade();
		std::cout << BLUE << one << RESET << std::endl;
	} catch(const Bureaucrat::GradeTooLowException &e) {
		std::cerr << YELLOW << "Decrement error: " << e.what() << RESET << std::endl;
	}
}

/**
 * @brief Creates a Bureaucrat object. If the grade is out of bounds, an exception is caught, 
 * and a default Bureaucrat is returned.
 * 
 * @param name The name of the Bureaucrat to create.
 * @param grade The grade of the Bureaucrat to create.
 * @return Bureaucrat A Bureaucrat object with the specified name and grade, or a default 
 * Bureaucrat if an error occurred.
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

/**
 * @brief The main function demonstrating the Bureaucrat class.
 */
int	main( void ) {
	Bureaucrat	peter = createBureaucrat("Peter", 149);
	Bureaucrat	perkins = createBureaucrat("Perkins", 2);
	Bureaucrat	wrongPeter = createBureaucrat("Wrong Peter", 151);
	Bureaucrat	wrongPerkins = createBureaucrat("Wrong Perkins", 0);

	checkDecrement(peter);
	checkDecrement(peter);
	checkIncrement(peter);
	checkIncrement(perkins);
	checkIncrement(perkins);
	checkDecrement(perkins);
	return (0);
}