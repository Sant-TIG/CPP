/**
 * @file RobotomyRequestForm.hpp
 * @brief Declaration of the RobotomyRequestForm class.
 *
 * This file contains the declaration of the RobotomyRequestForm class,
 * which represents a specific type of form for requesting a robotomy. 
 * The class inherits from the AForm base class and implements 
 * functionality for signing and executing the robotomy request form.
 */

#ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

/**
 * @class RobotomyRequestForm
 * @brief Class representing a form for robotomy request.
 */
class RobotomyRequestForm : public AForm{
	private:
		static const unsigned int	_signGrade = 72; ///< Required grade to sign the form.
		static const unsigned int	_execGrade = 45; ///< Required grade to execute the form.
		std::string			_target; ///< The target for which the robotomy is requested.

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string &target );
		RobotomyRequestForm( const RobotomyRequestForm &otherRobotomyRequestForm );
		~RobotomyRequestForm( void );

		RobotomyRequestForm & operator=( const RobotomyRequestForm &otherRobotomyRequestForm );

		const std::string	&getTarget( void ) const;

		void		executeForm( void ) const;
};

#endif
