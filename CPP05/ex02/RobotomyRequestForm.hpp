/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:41:06 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:40:02 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H

# define ROBOTOMYREQUESTFORM_H

# include "Colors.hpp"
# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm{
	private:
		static const int	_signGrade = 72;
		static const int	_execGrade = 45;
		std::string			_target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string &target );
		RobotomyRequestForm( const RobotomyRequestForm &oneRobotomyRequestForm );
		RobotomyRequestForm & operator=( const RobotomyRequestForm &oneRobotomyRequestForm );
		~RobotomyRequestForm( void );

		std::string	getTarget( void ) const;
		void		executeForm( void ) const;
};

#endif
