/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:33:56 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 16:33:59 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * Creates a new Zombie object with the given name and immediately calls the
 * announce method.
 * Parameters:
 *     name: name to be assigned to the new Zombie
 */
void	randomChump( const std::string &name ) {
	Zombie	newZombie(name);
	newZombie.announce();
}
