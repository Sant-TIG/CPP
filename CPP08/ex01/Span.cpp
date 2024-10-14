/**
 * @file Span.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the Span class for managing a collection of integers and calculating the shortest and longest spans.
 * @date 2024-08-06
 */

#include "Span.hpp"


/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new Span object with default values.
 */
Span::Span( void ) : _maxSize(0) {
	std::cout << GREEN << "Span default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Span object with the values passed as parameters.
 *
 * @param maxSize The maximum number of integers the Span object can store
 */
Span::Span( unsigned int maxSize ) : _maxSize(maxSize) {
	std::cout << GREEN << "Span parameterized constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new Span object by copying the values from another object.
 *
 * @param oneSpan A reference to the Span object to be copied.
 */
Span::Span( const Span &oneSpan ) : _maxSize(oneSpan.getN()) {
	std::cout << GREEN << "Span copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the Span object.
 */
Span::~Span( void ) {
	std::cout << RED << "Span destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the Span class.
 *
 * @param oneSpan The source Span object to assign from.
 * @return Span& A reference to the current Span object after assignment.
 */
Span & Span::operator=( const Span &oneSpan ) {
	if (this != &oneSpan) {
		_maxSize = oneSpan.getN();
	}
	return *this;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the amount of numbers the Span class can store.
 *
 * @return _maxSize A constant reference to the storage capacity.
 */
const unsigned int	&Span::getN( void ) const {
	return _maxSize;
}

/* ------------ SETTER METHODS ------------ */

/**
 * @brief Sets storage capacity.
 * 
 * @param maxSize The new storage capacity.
 */
void	Span::setN( unsigned int maxSize ) {
	_maxSize = maxSize;
}


/* ------------ MEMBER METHODS ------------ */

/**
 * @brief Adds a number to the vector of Span object.
 *
 * @param nbr The integer to add to the container.
 * @throw std::out_of_range if the container is already at full capacity.
 */
void	Span::addNumber( int nbr ) {
	if (_numbers.size() == _maxSize) {
		throw std::out_of_range("Error: The container is at full capacity.");
	}
	_numbers.push_back(nbr);
}

/**
 * @brief Adds a sequence of numbers to the Span object.
 *
 * @param start An iterator pointing to the start of the sequence.
 * @param end An iterator pointing to the end of the sequence.
 */
void	Span::addSequence( VectorIt start, VectorIt end ) {
	_numbers.insert(_numbers.end(), start, end);
}

/**
 * @brief Calculates the shortest span between any two numbers in the Span object.
 *
 * Finds the smallest difference between any two consecutive numbers in the sorted container.
 *
 * @return int The shortest span between any two numbers.
 * @throw std::length_error if there are less than two numbers in the container.
 */
int	Span::shortestSpan( void ) {
	if (_numbers.size() < 2) {
		throw std::length_error("Error: Not enough numbers to find a span.");
	}
	sort(_numbers.begin(), _numbers.end());
	int	min_span = INT_MAX;
	int	curr_span;
	for (int i = 1; i < (int)_numbers.size(); i++) {
		curr_span = _numbers[i] - _numbers[i - 1];
		if (curr_span < min_span) {
			min_span = curr_span;
		}
	}
	return min_span;
}

/**
 * @brief Calculates the longest span between the minimum and maximum numbers in the vector of Span object.
 *
 * @return int The longest span between the smallest and largest numbers.
 */
int	Span::longestSpan( void ) {
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

/**
 * @brief Prints all the numbers stored in the Span object.
 */
void Span::printVector( void ) {
	for (VectorIt it = _numbers.begin(); it != _numbers.end(); it++) {
		std::cout << *it << std::endl;
	}
}