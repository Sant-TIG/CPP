#include "Weapon.hpp"
#include <iostream>
#include "Colors.hpp"

/*
 * Default constructor. Initializes instance variables to 0.
 */
Weapon::Weapon( void ) : type("") {
	std::cout << "Weapon default constructor called" << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
Weapon::Weapon( const std::string &oneType ) : type(oneType) {
	std::cout << "Weapon: " << this->type << " created" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Weapon::Weapon( const Weapon &oneWeapon ) : type(oneWeapon.type) {
	std::cout << "Weapon copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Weapon & Weapon::operator=( const Weapon &oneWeapon ) {
	if (this != &oneWeapon) {
		type = oneWeapon.type;
	}
	return *this;
}

/*
 * Destructor.
 */
Weapon::~Weapon( void ) {
	std::cout << type << " destroyed" << std::endl;
}

/*
 * Getter methods
 */
const std::string&	Weapon::getType( void ) {
	return type;
}

/*
 * Setter methods
 */
void	Weapon::setType( const std::string &otherType ) {
	type = otherType;
}