/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:33:37 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:39:26 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H

# define FORM_H

# include "Colors.hpp"
# include "Bureaucrat.hpp"
# include <string>
# include <exception>

class Bureaucrat;

class	AForm {
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	protected:
		virtual void executeForm() const = 0;

	public:
		AForm( void );
		AForm( const std::string &name, const int _signGrade, const int _execGrade);
		AForm( const AForm &oneAForm );
		AForm & operator=( const AForm &oneAForm );
		virtual ~AForm( void ) = 0;

		const std::string	getName( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;
		bool				getSigned( void ) const;
		void				setSigned( bool sign );

		void				beSigned( const Bureaucrat &peter );
		virtual void		execute( const Bureaucrat &executor ) const;

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

std::ostream	&operator<<( std::ostream &os, const AForm &oneAForm );

#endif
