
#ifndef ZOMBIE_H

# define ZOMBIE_H

# include <iostream>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie( void );
		Zombie( const std::string &name );
		Zombie( const Zombie &oneZombie );
		Zombie & operator=( const Zombie &oneZombie );
		~Zombie( void );
		std::string	getName( void );
		void		announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( const std::string &name );

#endif
