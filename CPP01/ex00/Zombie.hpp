/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:33:01 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 16:34:20 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_H

# define ZOMBIE_H

# include <iostream>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie( void );
		Zombie( const std::string &name );
		Zombie( const Zombie &oneZombie );
		Zombie & operator=( const Zombie &oneZombie );
		~Zombie( void );
		std::string	getName( void );
		void		announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( const std::string &name );

#endif
