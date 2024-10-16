/**
 * @file EasyFind.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Template function to find an element in a container.
 * @date 2024-08-06
 */

#ifndef EASYFIND_HPP

# define EASYFIND_HPP

# include "../incs/Colors.hpp"

# include <stdexcept>
# include <sstream>
# include <algorithm>


/**
 * @brief Finds an element in a container.
 *
 * @tparam T The type of the container.
 * @param container The container in which to search for the element.
 * @param nbr The integer to find in the container.
 * @return typename T::iterator An iterator to the found element.
 * @throw std::runtime_error if the element is not found in the container.
 */
template <typename T>
typename T::iterator	easyfind( T &container, int nbr ) {
	typename T::iterator	it = find(container.begin(), container.end(), nbr);
	if (it == container.end()) {
        std::ostringstream oss;
        oss << nbr;
        std::string msg = "The number " + oss.str() + " is not in the cointainer.";
		throw std::runtime_error(msg);
	}
	return it;
}

#endif