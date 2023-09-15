/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:45:30 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:45:31 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H

# define CLAPTRAP_H

# include <string>
# include <iostream>
# include <typeinfo>

class ClapTrap {
	protected:
		std::string	name;
		int			health;
		int			energy;
		int			damage;

	public:
		ClapTrap( void );
		ClapTrap( const std::string &name );
		ClapTrap( const ClapTrap &oneClapTrap );
		ClapTrap & operator=( const ClapTrap &oneClapTrap );
		virtual ~ClapTrap( void );
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif
