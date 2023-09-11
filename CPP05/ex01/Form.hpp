/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:33:37 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 15:05:48 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H

# define FORM_H

# include "Colors.hpp"
# include "Bureaucrat.hpp"
# include <string>
# include <exception>

class Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	public:
		Form( void );
		Form( const std::string &name, const int _signGrade, const int _execGrade);
		Form( const Form &oneForm );
		Form & operator=( const Form &oneForm );
		~Form( void );

		const std::string	getName( void ) const;
		int			getSignGrade( void ) const;
		int			getExecGrade( void ) const;
		bool		getSigned( void ) const;

		void		beSigned( const Bureaucrat &peter );

	class	GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade too high to be signed";
			}
	};

	class	GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade too low to be signed";
			}
	};
};

std::ostream	&operator<<( std::ostream &os, const Form &oneForm );

#endif
