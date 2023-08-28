#ifndef	HUMANB_H

# define HUMANB_H

# include <string>
# include <iostream>
# include "Weapon.hpp"
# include "Colors.hpp"

class HumanB {
	private:
		std::string name;
		Weapon		*weapon;

	public:
		HumanB( void );
		HumanB( const std::string &name );
		HumanB( const std::string &name, const Weapon &oneWeapon );
		HumanB( const HumanB &oneHuman );
		HumanB & operator=( const HumanB &oneHuman );
		~HumanB( void );
		void	attack( void );
		void	setWeapon( Weapon &oneWeapon );
};

#endif