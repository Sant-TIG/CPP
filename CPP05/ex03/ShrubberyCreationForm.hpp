/**
 * @file ShrubberyCreationForm.hpp
 * @brief Declaration of the ShrubberyCreationForm class.
 *
 * This file contains the declaration of the ShrubberyCreationForm class, 
 * which represents a form for creating shrubbery. The class inherits from 
 * the AForm base class and implements functionality for signing and 
 * executing the form.
 */

#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

/**
 * @class ShrubberyCreationForm
 * @brief Class representing a form for shrubbery creation.
 */
class ShrubberyCreationForm : public AForm {
	private:
		static const unsigned int	_signGrade = 145; ///< Required grade to sign the form.
		static const unsigned int	_execGrade = 137; ///< Required grade to execute the form.
		std::string			_target; ///< The target for which the shrub is created.

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string &target );
		ShrubberyCreationForm( const ShrubberyCreationForm &otherShrubberyCreationForm );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm & operator=( const ShrubberyCreationForm &otherShrubberyCreationForm );

		const std::string	&getTarget( void ) const;

		void		executeForm( void ) const;
};

#endif
