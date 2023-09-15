#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main() {
	ClapTrap one("One");
	ClapTrap two("Two");
	ClapTrap three("Three");

	one.printObject();
	two.printObject();
	three.printObject();
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
	one.printObject();
	two.printObject();
	three.printObject();

	std::cout << "\n\nSCAVTRAPS\n" << std::endl;

	ScavTrap four("Four");
	ScavTrap five("Five");
	ScavTrap six("Six");

	four.printObject();
	five.printObject();
	six.printObject();
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
	four.printObject();
	five.printObject();
	six.printObject();

	std::cout << "\n\nFRAGTRAP\n" << std::endl;

	FragTrap seven("seven");
	FragTrap eight("eight");
	FragTrap nine("nine");

	seven.printObject();
	eight.printObject();
	nine.printObject();
	for (int i = 0; i < 12; i++)
	{
		seven.attack("Peter Perkins");
	}
	eight.takeDamage(5);
	eight.takeDamage(5);
	eight.takeDamage(5);
	eight.beRepaired(10);
	eight.takeDamage(1);
	for (int i = 0; i < 13; i++)
	{
		nine.takeDamage(5);
		nine.beRepaired(5);
	}
	seven.highFivesGuys();
	eight.highFivesGuys();
	nine.highFivesGuys();
	seven.printObject();
	eight.printObject();
	nine.printObject();

	std::cout << "\n\nDIAMONDTRAP\n" << std::endl;

	DiamondTrap ten("ten");
	DiamondTrap eleven("eleven");
	DiamondTrap twelve("twelve");

	ten.printObject();
	eleven.printObject();
	twelve.printObject();
	for (int i = 0; i < 12; i++)
	{
		ten.attack("Peter Perkins");
	}
	eleven.takeDamage(5);
	eleven.takeDamage(5);
	eleven.takeDamage(5);
	eleven.beRepaired(10);
	eleven.takeDamage(1);
	for (int i = 0; i < 13; i++)
	{
		twelve.takeDamage(5);
		twelve.beRepaired(5);
	}
	ten.whoAmI();
	eleven.whoAmI();
	twelve.whoAmI();
	ten.printObject();
	eleven.printObject();
	twelve.printObject();
}