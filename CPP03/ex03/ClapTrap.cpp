
#include "ClapTrap.hpp"

/*
 * Default constructor. Initializes instance variables to 0.
 */
ClapTrap::ClapTrap( void ) : name(""), health(0), energy(0), damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
ClapTrap::ClapTrap( const std::string &name ) : name(name), health(10), energy(10), damage(0) {
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
ClapTrap::ClapTrap( const ClapTrap &oneClapTrap ) {
	*this = oneClapTrap;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
ClapTrap & ClapTrap::operator=( const ClapTrap &oneClapTrap ) {
	if (this != &oneClapTrap) {
		name = oneClapTrap.name;
		health = oneClapTrap.health;
		energy = oneClapTrap.energy;
		damage = oneClapTrap.damage;
	}
	return *this;
}

/*
 * Destructor.
 */
ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

/*
 * Make the ClapTrap attack a target
 * Parameters:
 *     target: the taget entity to be attacked
 */
void	ClapTrap::attack( const std::string& target ) {
	if (energy > 0) {
		std::cout << getClassName() << " " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
		energy--;
	} else {
		std::cout << getClassName() << " " << name << " hasn't energy." << std::endl;
	}
}

/*
 * Make the ClapTrap take damage
 * Parameters:
 *     amount: the amount of damage bein taken
 */
void	ClapTrap::takeDamage( unsigned int amount ) {
	if (health > 0) {
		std::cout << getClassName() << " " << name << " takes " << amount << " points of damage." << std::endl;
		health -= amount;
	} else {
		std::cout << getClassName() << " " << name << " is dead." << std::endl;
	}
}

/*
 * Repair the ClaptTrap and recover health
 * Parameters:
 *     amount: the amount of health points being recovered
 */
void	ClapTrap::beRepaired( unsigned int amount ) {
	if (energy > 0) {
		std::cout << getClassName() << " " << name << " has recovered " << amount << " health points." << std::endl;
		health += amount;
		energy--;
	} else {
		std::cout << getClassName() << " " << name << " hasn't energy." << std::endl;
	}
}

std::string	ClapTrap::getClassName( void ) {
	std::string className = typeid(*this).name();
	size_t i = 0;
	while (i < className.size() && std::isdigit(className[i])) {
		i++;
	}
	if (i != 0) {
		className = className.substr(i);
	}
	return className;
}

void	ClapTrap::printObject( void ) {
	std::cout << getClassName() << " " << name << " features:"
			  << "\nhealth: " << health
			  << "\nenergy: " << energy
			  << "\ndamage: " << damage << std::endl;
}