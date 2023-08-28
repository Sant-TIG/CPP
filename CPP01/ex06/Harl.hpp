
#ifndef HARL_H

# define HARL_H

# include <string>

class Harl {
	private:
		static const int			NBR_LEVELS = 4;
		static const std::string	LEVELS[NBR_LEVELS];

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		Harl( void );
		Harl( const Harl &oneHarl );
		Harl & operator=( const Harl &oneHarl );
		~Harl( void );

		void	complain( const std::string &level );
		int		getLevelIndex( const std::string &level );
};

#endif
