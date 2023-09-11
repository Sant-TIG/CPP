/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:48:32 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 15:05:44 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H

# define BUREAUCRAT_H

# include "Colors.hpp"
# include "Form.hpp"
# include <string>
# include <exception>

class Form;

class Bureaucrat {
	private:
		static const int	HIGHEST_GRADE = 1;
		static const int	LOWEST_GRADE = 150;

		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &oneBureaucrat );
		Bureaucrat & operator=( const Bureaucrat &oneBureaucrat );
		~Bureaucrat( void );

		const std::string	getName( void ) const;
		int					getGrade( void ) const;

		void				incrementGrade( void );
		void				decrementGrade( void );
		bool				checkGrade( int grade ) const;
		void				signForm( Form &oneForm );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is to high";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is to low";
				}
		};
};

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &oneBureaucrat );

#endif
