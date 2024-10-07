
#ifndef AFORM_H

# define AFORM_H

# include "../incs/Colors.hpp"
# include "Bureaucrat.hpp"

# include <string>
# include <exception>

class Bureaucrat;

class	AForm {
	private:
		const std::string	_name; ///< Name of the form
		const unsigned int			_signGrade; ///< Grade required to sign the form
		const unsigned int			_execGrade; ///< Grade required to execute the form
		bool				_signed; ///< Whether the form has been signed

	protected:
		virtual void executeForm() const = 0;

	public:
		AForm( void );
		AForm( const std::string &name, const unsigned int _signGrade, const unsigned int _execGrade);
		AForm( const AForm &otherAForm );
		AForm & operator=( const AForm &otherAForm );
		virtual ~AForm( void ) = 0;

		const std::string	&getName( void ) const;
		unsigned int			        getSignGrade( void ) const;
		unsigned int			        getExecGrade( void ) const;
		bool		        getSigned( void ) const;

		void				setSigned( bool sign );

		void				beSigned( const Bureaucrat &bureaucrat );
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

std::ostream	&operator<<( std::ostream &os, const AForm &otherAForm );

#endif
