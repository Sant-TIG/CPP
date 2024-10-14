/**
 * @file Functions.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Header file for generic template functions: swap, min, and max.
 * @date 2024-08-06
 */

#ifndef FUNCTIONS_HPP

# define FUNCTIONS_HPP

/**
 * @brief Swaps the values of the two provided arguments.
 * 
 * @tparam T The type of the variables to swap.
 * @param val1 The first value, which will receive the value of val2.
 * @param val2 The second value, which will receive the value of val1.
 */
template <typename T>
void	swap( T &val1, T &val2 ) {
	T	tmp = val1;
	val1 = val2;
	val2 = tmp;
}

/**
 * @brief Returns the smaller of the two values.
 * 
 * @tparam T The type of the variables to compare.
 * @param val1 The first value.
 * @param val2 The second value.
 * @return T The smaller of the two values.
 */
template <typename T>
T	min( T val1, T val2 ) {
	if (val1 < val2) {
		return val1;
	}
	return val2;
}

/**
 * @brief Returns the larger of the two values.
 * 
 * @tparam T The type of the variables to compare.
 * @param val1 The first value.
 * @param val2 The second value.
 * @return T The larger of the two values.
 */
template <typename T>
T	max( T val1, T val2 ) {
	if (val1 > val2) {
		return val1;
	}
	return val2;
}

#endif