/**
 * @file Base.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Definition of the Base class for polymorphic behavior.
 * @date 2024-07-29
 * 
 * @details This header file declares the Base class, which serves as the superclass for all derived 
 * classes in the application. The Base class provides a virtual destructor to ensure proper 
 * cleanup of resources for derived classes. This enables polymorphism and facilitates 
 * dynamic type identification.
 */
#ifndef BASE_HPP

# define BASE_HPP

# include "../incs/Colors.hpp"
# include <iostream>

class Base {
	public:
		virtual ~Base( void );
};

#endif