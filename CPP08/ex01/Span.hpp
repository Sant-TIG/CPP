/**
 * @file Span.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Definition of the Span class for managing a collection of integers and calculating the shortest and longest spans.
 * @date 2024-08-06
 */

#ifndef SPAN_HPP

# define SPAN_HPP

# include "Colors.hpp"

# include <iostream>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <climits>

typedef std::vector<int>::iterator	VectorIt;

/**
 * @class Span
 * @brief A class for storing integers and calculating the shortest and longest spans.
 *
 * The Span class allows the user to store a collection of integers up to a specified maximum size
 * and provides methods to calculate the shortest and longest spans between the stored integers.
 */
class Span {
	private:
		unsigned int		_maxSize;///< The maximum number of integers that can be stored
		std::vector<int>	_numbers;///< The container storing the integers.

	public:
		Span( void );
		Span( unsigned int maxSize );
		Span( const Span &oneSpan );
		Span & operator=( const Span &oneSpan );
		~Span( void );

		const unsigned int	&getN( void ) const;
		void				setN( unsigned int maxSize );

		void	addNumber( int nbr );
		void	addSequence( VectorIt start, VectorIt end );
		int		shortestSpan( void );
		int		longestSpan( void );
		void	printVector( void );
};

#endif
