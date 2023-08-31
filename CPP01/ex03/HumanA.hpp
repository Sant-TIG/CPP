#ifndef HUMANA_H

# define HUMANA_H

# include "Weapon.hpp"
# include "Colors.hpp"
# include <string>
# include <iostream>

class HumanA {
	private:
		std::string	name;
		Weapon&		weapon;

	public:
		HumanA( const Weapon &oneWeapon );
		HumanA( const std::string &name, const Weapon &oneWeapon );
		HumanA( const HumanA &oneHumanA );
		HumanA & operator=( const HumanA &oneHumanA );
		~HumanA( void );
		void	attack( void );
};

#endif
