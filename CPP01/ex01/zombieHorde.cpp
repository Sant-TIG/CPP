/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:32:11 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 17:32:12 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * Creates a horde of Zombie objects with the given name and announces each Zombie.
 * Dynamically allocates memory for an array of Zombie instances.
 * Parameters:
 *     N: the number of Zombies to be created in the horde
 *     name: the name to be assigned to all Zombies in the horde
 * Return:
 *     A pointer to the first Zombie in the newly created horde
 */
Zombie*	zombieHorde( int N, std::string name ) {
	Zombie*	newHorde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		newHorde[i].setName(name);
		newHorde[i].announce();
	}
	return newHorde;
}
