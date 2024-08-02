/**
 * @file RPN.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Header file for the RPN class, which evaluates expressions in Reverse Polish Notation.
 * @date 2024-07-29
 */

#ifndef RPN_H

# define RPN_H

# include <stack>
# include <sstream>
# include <string>
# include <iostream>
# include <cstdlib>

# include "Colors.hpp"

typedef	std::stack<double>	Stack;

class RPN {
	private:
		static bool	strIsNumber( const std::string &str );
		static double	popStack( Stack &stack );
		static void	applyOperator( Stack &stack, const std::string &opt );

	public:
		RPN( void );
		RPN( const RPN &oneRPN );
		RPN & operator=( const RPN &oneRPN );
		~RPN( void );

		static void	evaluateExpression( const std::string &expression );

	public:
		/**
		 * @class StackError
		 * @brief Exception class for errors related to stack operations.
		 */
		class	StackError : public std::exception {
			private:
				std::string _msg; ///< Error message.

			public:
				/**
				 * @brief Constructor for the StackError class.
				 * @param msg The error message.
				 */
				StackError( const std::string &msg ) throw() : _msg("RPN: stack_error: " + msg) {}
				/**
				 * @brief Destructor for the StackError class.
				 */
				~StackError( void ) throw() {}
				/**
				 * @brief Gets the error message.
				 * @return The error message as a C-style string.
				 */
				virtual const char	*what() const throw() {
					return _msg.c_str();
				}

		};
};

#endif
