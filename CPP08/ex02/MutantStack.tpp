/**
 * @file MutantStack.tpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the MutantStack class template methods.
 *
 * The MutantStack class template is a custom stack data structure that inherits 
 * from `std::stack`. It adds iterator functionality to the stack, allowing it to
 * be iterated like a container.
 *
 * @tparam T The type of elements stored in the stack.
 * @tparam Container The type of the underlying container used by the stack.
 *
 * @note This file should be included at the end of the corresponding MutantStack.hpp file
 * to ensure that the template methods are correctly instantiated.
 *
 * @date 2024-08-12
 */

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new MutantStack object with default values.
 */
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack( void ) : std::stack<T, Container>() {
}

/**
 * @brief Construct a new MutantStack object by copying the values from another object.
 *
 * @param aMutantStack A reference to the MutantStack object to be copied.
 */
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack( const MutantStack &aMutantStack ) : std::stack<T, Container>(aMutantStack) {
}

/**
 * @brief Destroy the MutantStack object.
 */
template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack( void ) {
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the MutantStack class.
 *
 * @param aMutantStack The source MutantStack object to assign from.
 * @return MutantStack& A reference to the current MutantStack object after assignment.
 */
template<typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=( const MutantStack &aMutantStack ) {
	this->c = aMutantStack.c;
	return *this;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Allows for iteration from the beginning of the stack.
 * 
 * @return iterator An iterator to the first element in the stack.
 */
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return this->c.begin();
}

/**
 * @brief Allows for iteration past the last element of the stack.
 * 
 * @return iterator An iterator to one past the last element in the stack.
 */
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
    return this->c.end();
}

/**
 * @brief Allows for constant iteration from the beginning of the stack.
 * 
 * @return const_iterator A constant iterator to the first element in the stack.
 */
template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const {
    return this->c.begin();
}

/**
 * @brief Allows for constant iteration past the last element of the stack.
 *
 * @return const_iterator A constant iterator to one past the last element in the stack.
 */
template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const {
    return this->c.end();
}

/**
 * @brief Allows for reverse iteration from the end of the stack.
 * 
 * @return reverse_iterator A reverse iterator to the last element in the stack.
 */
template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() {
    return this->c.rbegin();
}

/**
 * @brief Allows for reverse iteration past the first element of the stack.
 * 
 * @return reverse_iterator A reverse iterator to one past the first element in the stack.
 */
template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() {
    return this->c.rend();
}

/**
 * @brief Allows for constant reverse iteration from the end of the stack.
 *
 * @return const_reverse_iterator A constant reverse iterator to the last element in the stack.
 */
template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const {
    return this->c.rbegin();
}

/**
 * @brief Allows for constant reverse iteration past the first element of the stack.
 * 
 * @return const_reverse_iterator A constant reverse iterator to one past the first element in the stack.
 */
template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const {
    return this->c.rend();
}