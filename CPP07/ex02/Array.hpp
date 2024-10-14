#ifndef ARRAY_HPP

# define ARRAY_HPP

template <typename T>
class Array {
	private:
		T*			_data;
		std::size_t	_size;

	public:
		Array( void );
        Array( unsigned int size );
        Array( const Array &otherArray );

        ~Array( void );

        Array & operator=( const Array &otherArray );

        T& operator[](unsigned int index);

        unsigned int size() const;
};

# include "Array.tpp"

#endif
