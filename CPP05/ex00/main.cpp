/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:47:06 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 14:09:00 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
