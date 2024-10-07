/**
 * @file Form.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Declaration of the Form class, representing a form that can be signed by a Bureaucrat.
 * The form has specific grades required for signing and execution, and can throw exceptions if 
 * these grades are not met.
 * @date 2024-07-29
 */

#ifndef FORM_HPP

# define FORM_HPP

# include "../incs/Colors.hpp"
# include "Bureaucrat.hpp"

# include <string>

class Bureaucrat;

/**
 * @class Form
 * @brief Represents a form with a name, required grades for signing and execution, 
 * and a boolean to track if it has been signed.
 * 
 * The Form class holds essential details about a form that requires signatures from Bureaucrats 
 * with specific grades. It provides methods to retrieve form attributes, sign the form, and handle 
 * exceptions when the Bureaucrat's grade does not meet the required thresholds.
 */

class	Form {
	private:
		const std::string	_name; ///< The name of the form
		const unsigned int	_signGrade; ///< The grade required to sign the form
		const unsigned int	_execGrade; ///< The grade required to execute the form
		bool				_signed; ///< Status indicating whether the form has been signed

	public:
		Form( void );
		Form( const std::string &name, const int signGrade, const int execGrade, bool isSigned );
		Form( const Form &otherForm );
		~Form( void );

		Form & operator=( const Form &otherForm );

		const std::string	&getName( void ) const;
		const unsigned int	&getSignGrade( void ) const;
		const unsigned int  &getExecGrade( void ) const;
		bool		        getSigned( void ) const;

		void    beSigned( const Bureaucrat &bureaucrat );

    public:
    	/**
		 * @class GradeTooHighException
		 * @brief Exception thrown when the Bureaucrat's grade is too high to sign the form.
		 */
        class	GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too high to be signed";
                }
        };

        /**
		 * @class GradeTooHighException
		 * @brief Exception thrown when the Bureaucrat's grade is too low to sign the form.
		 */
        class	GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade too low to be signed";
                }
        };
};

std::ostream	&operator<<( std::ostream &os, const Form &otherForm );

#endif
