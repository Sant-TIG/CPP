/**
 * @file Bureaucrat.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Declaration of the Bureaucrat class.
 * @date 2024-07-29
 */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include "../incs/Colors.hpp"

# include <iostream>
# include <string>

/**
 * @class Bureaucrat
 * @brief Represents a bureaucrat with a name and a grade.
 * 
 * The Bureaucrat class models an individual with a specific grade, which must fall within a defined range. 
 * The class provides functionality to manage and validate the grade, and it throws exceptions if the grade is out of bounds.
 */
class Bureaucrat {
	private:
		static const int	HIGHEST_GRADE = 1; ///< The highest possible grade for a Bureaucrat.
		static const int	LOWEST_GRADE = 150; ///< The lowest possible grade for a Bureaucrat.

		const std::string	_name; ///< The name of the Bureaucrat, constant and cannot be changed.
		unsigned int		_grade; ///< The grade of the Bureaucrat, which can be incremented or decremented.

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string &name, unsigned int grade );
		Bureaucrat( const Bureaucrat &otherBureaucrat );
		~Bureaucrat( void );

		Bureaucrat & operator=( const Bureaucrat &otherBureaucrat );

		const std::string	&getName( void ) const;
		const unsigned int		&getGrade( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );
		bool	checkGrade( unsigned int grade ) const;

	public:
		/**
		 * @class GradeTooHighException
		 * @brief Exception thrown when a Bureaucrat's grade is too high.
		 */
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too high";
				}			
		};

		/**
		 * @class GradeTooLowException
		 * @brief Exception thrown when a Bureaucrat's grade is too low.
		 */
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too low";
				}
		};
};

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &aBureaucrat );

#endif
