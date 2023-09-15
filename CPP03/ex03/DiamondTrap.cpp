
#include "DiamondTrap.hpp"

/*
 * Default constructor. Initializes instance variables to 0.
 */
DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap(), _name("") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	_name = name;
	health = FragTrap::_initHealth;
	energy = ScavTrap::_initEnergy;
	damage = FragTrap::_damage;
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
DiamondTrap::DiamondTrap( const DiamondTrap &oneDiamondTrap ) : ClapTrap(oneDiamondTrap), ScavTrap(oneDiamondTrap), FragTrap(oneDiamondTrap) {
	*this = oneDiamondTrap;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
DiamondTrap & DiamondTrap::operator=( const DiamondTrap &oneDiamondTrap ) {
	if (this != &oneDiamondTrap) {
		name = oneDiamondTrap.name;
		health = oneDiamondTrap.health;
		energy = oneDiamondTrap.energy;
		damage = oneDiamondTrap.damage;
	}
	return *this;
}

/*
 * Destructor.
 */
DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI( void ) const {
	std::cout << "DiamondTrap's name: " << _name << std::endl;
	std::cout << "ClapTrap's name: " << name << std::endl;
}