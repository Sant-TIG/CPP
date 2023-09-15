
#ifndef SCAVTRAP_H

# define SCAVTRAP_H

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : virtual public ClapTrap {
	protected:
		static const int	_initHealth = 100;
		static const int	_initEnergy = 50;
		static const int	_damage = 20;

	public:
		ScavTrap( void );
		ScavTrap( const std::string &name );
		ScavTrap( const ScavTrap &oneScavTrap );
		ScavTrap & operator=( const ScavTrap &oneScavTrap );
		~ScavTrap( void );
		void	guardGate( void );
};

#endif
