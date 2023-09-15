/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:46:58 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:46:59 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_H

# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( const std::string &name );
		ScavTrap( const ScavTrap &oneScavTrap );
		ScavTrap & operator=( const ScavTrap &oneScavTrap );
		~ScavTrap( void );
		void	guardGate( void );
};

#endif
