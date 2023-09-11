/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:48:11 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/07 19:52:13 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H

# define PRESIDENTIALPARDONFORM_H

# include "Colors.hpp"
# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm {
	private:
		static const int	_signGrade = 25;
		static const int	_execGrade = 5;
		std::string			_target;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const std::string &target );
		PresidentialPardonForm( const PresidentialPardonForm &onePresidentialPardonForm );
		PresidentialPardonForm & operator=( const PresidentialPardonForm &onePresidentialPardonForm );
		~PresidentialPardonForm( void );

		std::string	getTarget( void ) const;
		void		executeForm( void ) const;
};

#endif
