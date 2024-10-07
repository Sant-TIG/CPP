/**
 * @file PresidentialPardonForm.hpp
 * @brief Declaration of the PresidentialPardonForm class.
 *
 * This file contains the declaration of the PresidentialPardonForm class,
 * which is a specific type of form for granting presidential pardons. 
 * The class inherits from the AForm base class and implements 
 * functionality for signing and executing the form.
 */

#ifndef PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

/**
 * @class PresidentialPardonForm
 * @brief Class representing a form for presidential pardon.
 */
class PresidentialPardonForm : public AForm {
	private:
		static const unsigned int	_signGrade = 25; ///< Required grade to sign the form.
		static const unsigned int	_execGrade = 5; ///< Required grade to execute the form.
		std::string			_target; ///< The target for which the presidential pardon is requested.

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const std::string &target );
		PresidentialPardonForm( const PresidentialPardonForm &otherPresidentialPardonForm );
		~PresidentialPardonForm( void );

		PresidentialPardonForm & operator=( const PresidentialPardonForm &otherPresidentialPardonForm );

		const std::string	&getTarget( void ) const;

		void		executeForm( void ) const;
};

#endif
