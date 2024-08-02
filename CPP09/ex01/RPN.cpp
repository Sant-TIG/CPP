/**
 * @file RPN.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the RPN class for evaluating Reverse Polish Notation expressions.
 * @date 2024-07-29
 */

#include "RPN.hpp"


/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new RPN object with default values.
 */
RPN::RPN( void ) {
	std::cout << GREEN << "RPN default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new RPN object by copying the values from another RPN object.
 *
 * @param oneRPN A reference to the RPN object to be copied.
 */
RPN::RPN( const RPN &oneRPN ) {
	*this = oneRPN;
	std::cout << GREEN << "RPN copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the BitcoinExchange object.
 */
RPN::~RPN( void ) {
	std::cout << RED << "RPN destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the RPN class.
 *
 * @param oneRPN The source RPN object to assign from.
 * @return &RPN A reference to the current RPN object after assignment.
 */
RPN & RPN::operator=( const RPN &oneRPN ) {
	if (this != &oneRPN) {}
	return *this;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Evaluates a mathematical expression in Reverse Polish Notation (RPN).
 *
 * This method takes a string representing an RPN expression and evaluates it using a stack.
 * It supports basic arithmetic operators: +, -, *, /. The method reads tokens from the expression,
 * pushes numbers onto the stack, and applies operators to the top elements of the stack.
 *
 * @param expression The RPN expression to be evaluated.
 * @throw StackError if the expression is invalid or contains invalid operators.
 */
void	RPN::evaluateExpression( const std::string &expression ) {
	std::stack<double>	stack;
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token) {
		if (strIsNumber(token)) {
			stack.push(strtod(token.c_str(), NULL));
		} else {
			if (stack.size() < 2) {
				throw StackError("invalid expression.");
			}
			applyOperator(stack, token);
		}
	}
	if (stack.size() != 1) {
		throw StackError("invalid expression.");
	} else {
		std::cout << stack.top() << std::endl;
	}
}

/**
 * @brief Checks if a given string represents a valid number.
 *
 * @param str The string to be checked.
 * @return true If the string represents a number
 * @return false If the string does not represent a number.
 */
bool	RPN::strIsNumber( const std::string &str ) {
	std::size_t	i = 0;

	if ((str[i] == '-')) {
		if (str.length() < 2) {
			return false;
		}
		i++;
	}
	while (i < str.length()) {
		if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
			return false;
		}
		i++;
	}
	return true;
}

/**
 * @brief Pops the top element from the stack.
 *
 * @param stack A reference to the stack from which the element is to be popped.
 * @return double The value of the top element that was popped from the stack.
 * @throw StackError if the stack is empty.
 */
double	RPN::popStack( Stack &stack ) {
	if (stack.empty()) {
		throw StackError("insufficient values in expression.");
	}

	double	value = stack.top();
	stack.pop();
	return value;
}

/**
 * @brief Applies an operator to the top two elements of the stack.
 *
 * This method pops the top two elements from the stack, applies the specified operator,
 * and pushes the result back onto the stack. Supported operators are: +, -, *, /.
 *
 * @param stack A reference to the stack containing the elements.
 * @param opt The operator to apply.
 * @throw StackError if the operator is invalid.
 */
void	RPN::applyOperator( Stack &stack, const std::string &opt ) {
	double	nbr1 = popStack(stack);
	double	nbr2 = popStack(stack);

	if (opt == "-") {
		stack.push(nbr2 - nbr1);
	} else if (opt == "+") {
		stack.push(nbr2 + nbr1);
	} else if (opt == "*") {
		stack.push(nbr2 * nbr1);
	} else if (opt == "/") {
		stack.push(nbr2 / nbr1);
	} else {
		throw StackError("invalid operator: " + opt);
	}
}