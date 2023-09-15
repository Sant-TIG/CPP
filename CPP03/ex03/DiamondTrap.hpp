
#ifndef DIAMONDTRAP_H

# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;

	public:
		DiamondTrap( void );
		DiamondTrap( const std::string &name );
		DiamondTrap( const DiamondTrap &oneDiamondTrap );
		DiamondTrap & operator=( const DiamondTrap &oneDiamondTrap );
		~DiamondTrap( void );

		void	whoAmI( void ) const;
};

#endif
