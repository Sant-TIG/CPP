/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:40:57 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/07 19:51:58 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H

# define SHRUBBERYCREATIONFORM_H

# include "Colors.hpp"
# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm {
	private:
		static const int	_signGrade = 145;
		static const int	_execGrade = 137;
		std::string			_target;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string &target );
		ShrubberyCreationForm( const ShrubberyCreationForm &oneShrubberyCreationForm );
		ShrubberyCreationForm & operator=( const ShrubberyCreationForm &oneShrubberyCreationForm );
		~ShrubberyCreationForm( void );

		std::string	getTarget( void ) const;
		void		executeForm( void ) const;
};

#endif
