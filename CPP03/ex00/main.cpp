/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:39:30 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:39:31 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap one("One");
	ClapTrap two("Two");
	ClapTrap three("Three");

	for (int i = 0; i < 12; i++) {
		one.attack("Peter Perkins");
	}
	two.takeDamage(5);
	two.takeDamage(5);
	two.takeDamage(5);
	two.beRepaired(10);
	two.takeDamage(1);
	for (int i = 0; i < 13; i++) {
		three.takeDamage(5);
		three.beRepaired(5);
	}
}
