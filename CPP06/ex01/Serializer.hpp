#ifndef SERIALIZER_HPP

# define SERIALIZER_HPP

# include "../incs/Colors.hpp"
# include "Data.h"
# include <string>
# include <iostream>
# include <stdint.h>

class Serializer {
	private:
		Serializer( void );
		Serializer( const Serializer &otherSerialize );
		Serializer & operator=( const Serializer &otherSerialize );
		~Serializer( void );

	public:
		static uintptr_t serialize( Data* ptr );
		static Data* deserialize( uintptr_t raw );
};

#endif