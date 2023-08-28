#ifndef WEAPON_H

# define WEAPON_H

# include <string>

class Weapon {
	private:
		std::string	type;

	public:
		Weapon( void );
		Weapon( const std::string &type );
		Weapon( const Weapon &oneWeapon);
		Weapon & operator=( const Weapon &oneWeapon );
		~Weapon( void );
		const std::string&	getType( void );
		void				setType( const std::string &type );
};

#endif