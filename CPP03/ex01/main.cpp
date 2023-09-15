/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:42:18 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/08 17:42:19 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"
#include	"ScavTrap.hpp"

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

	std::cout << "\n\nSCAVTRAPS\n" << std::endl;

	ScavTrap four("Four");
	ScavTrap five("Five");
	ScavTrap six("Six");

	for (int i = 0; i < 12; i++)
	{
		four.attack("Peter Perkins");
	}
	five.takeDamage(5);
	five.takeDamage(5);
	five.takeDamage(5);
	five.beRepaired(10);
	five.takeDamage(1);
	for (int i = 0; i < 13; i++)
	{
		six.takeDamage(5);
		six.beRepaired(5);
	}
	four.guardGate();
	five.guardGate();
	six.guardGate();
}
