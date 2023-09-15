/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:42:01 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:42:02 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H

# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( const std::string &name );
		ScavTrap( const ScavTrap &oneScavTrap );
		ScavTrap & operator=( const ScavTrap &oneScavTrap );
		~ScavTrap( void );
		void	guardGate( void );
};

#endif
