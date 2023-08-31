/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:33:33 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 16:33:45 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	Zombie*	heapZombie = newZombie("Quino");
	heapZombie->announce();
	delete heapZombie;
	randomChump("Mi inquilino");
	return 0;
}
