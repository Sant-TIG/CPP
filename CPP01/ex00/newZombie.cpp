/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:34:07 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 16:34:09 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * Creates and returns a new zombie object. Dinamycally allocates memory for a
 * Zombie instance and intializes it with the given name.
 * Parameters:
 *     name: the name to be assigned to the new Zombie
 * Returns:
 *     A pointer to the newly created Zombie object.
 */
Zombie*	newZombie( std::string name ) {
	return new Zombie(name);
}
