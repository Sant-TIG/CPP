#include "HumanA.hpp"

/*
 * Default constructor. Initializes instance variables
 */
HumanA::HumanA( const Weapon &oneWeapon ) : name(""), weapon((Weapon &)oneWeapon) {
	std::cout << "HumanA default constructor called" << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
HumanA::HumanA( const std::string &name, const Weapon &oneWeapon ) : name(name), weapon((Weapon &)oneWeapon) {
	std::cout << "HumanA parameterized constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
HumanA::HumanA( const HumanA &oneHumanA ) : name(oneHumanA.name), weapon(oneHumanA.weapon) {
	std::cout << "HumanA copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
HumanA & HumanA::operator=( const HumanA &oneHumanA ) {
	if (this != &oneHumanA) {
		name = oneHumanA.name;
		weapon = oneHumanA.weapon;
	}
	return *this;
}

/*
 * Destructor.
 */
HumanA::~HumanA( void ) {
	std::cout << "HumanA destructor called" << std::endl;
}

/*
 * Displays a message indicating that the HumanA is attacking with their weapon
 */
void	HumanA::attack( void ) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}