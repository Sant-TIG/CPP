/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:46:46 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:46:47 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_H

# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap( void );
		FragTrap( const std::string &name );
		FragTrap( const FragTrap &oneFragTrap );
		FragTrap & operator=( const FragTrap &oneFragTrap );
		~FragTrap( void );
		void	highFivesGuys( void );
};

#endif
