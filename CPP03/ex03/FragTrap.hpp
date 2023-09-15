
#ifndef FRAGTRAP_H

# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		static const int	_initHealth = 100;
		static const int	_initEnergy = 100;
		static const int	_damage = 30;

	public:
		FragTrap( void );
		FragTrap( const std::string &name );
		FragTrap( const FragTrap &oneFragTrap );
		FragTrap & operator=( const FragTrap &oneFragTrap );
		~FragTrap( void );
		void	highFivesGuys( void );
};

#endif
