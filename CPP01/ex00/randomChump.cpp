#include "Zombie.hpp"

/*
 * Creates a new Zombie object with the given name and immediately calls the
 * announce method.
 * Parameters:
 *     name: name to be assigned to the new Zombie
 */
void	randomChump( const std::string &name ) {
	Zombie	newZombie(name);
	newZombie.announce();
}