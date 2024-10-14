/**
 * @file Iter.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Template function to apply a given function to each element of an array.
 * 
 *  The function is templated to work with any type of array and function.
 * 
 * @date 2024-08-12
 */

#ifndef ITER_HPP

# define ITER_HPP

# include <cstddef>

/**
 * @brief Applies a function to each element of an array.
 * 
 * This template function iterates over an array and applies a provided function 
 * to each element of the array. It is designed to work with arrays of any type and 
 * function objects that operate on the elements of the array.
 * 
 * @tparam T The type of elements in the array.
 * @tparam F The type of the function to be applied to each element.
 * @param array A pointer to the first element of the array.
 * @param size The number of elements in the array.
 * @param function The function to apply to each element of the array.
 */
template <typename T, typename F>
void	iter( T *array, std::size_t size, F function ) {
	for (std::size_t i = 0; i < size; i++) {
		function(array[i]);
	}
}

#endif