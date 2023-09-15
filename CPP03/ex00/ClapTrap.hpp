/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:39:15 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:39:16 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H

# define CLAPTRAP_H

# include <string>
# include <iostream>
# include <typeinfo>

class ClapTrap {
	private:
		std::string	name;
		int			health;
		int			energy;
		int			damage;

	public:
		ClapTrap( void );
		ClapTrap( const std::string &name );
		ClapTrap( const ClapTrap &oneClapTrap );
		ClapTrap & operator=( const ClapTrap &oneClapTrap );
		~ClapTrap( void );
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif
