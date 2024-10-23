#include "PmergeMe.hpp"

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new PmergeMe object with default values.
 */
PmergeMe::PmergeMe( void ) : _vector(), _deque() {}

/**
 * @brief Construct a new PmergeMe object with the values passed as parameters.
 *
 */
PmergeMe::PmergeMe( int argc, char **argv ) {
    addNumbers(argc, argv);

}

/**
 * @brief Construct a new PmergeMe object by copying the values from another PmergeMe object.
 *
 * @param other A reference to the PmergeMe object to be copied.
 */
PmergeMe::PmergeMe( const PmergeMe &other ) : _vector(other._vector), _deque(other._deque) {}

/**
 * @brief Destroy the PmergeMe object.
 */
PmergeMe::~PmergeMe( void ) {}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the PmergeMe class.
 *
 * @param other The source PmergeMe object to assign from.
 * @return PmergeMe& A reference to the current PmergeMe object after assignment.
 */
PmergeMe &PmergeMe::operator=( const PmergeMe &other ) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the database data.
 *
 * @return const DataMap& A constant reference to the internal data map.
 */
Vector    &PmergeMe::getVector( void ) {
    return _vector;
}

/**
 * @brief Retrieves the database data.
 *
 * @return const DataMap& A constant reference to the internal data map.
 */
Deque    &PmergeMe::getDeque( void ) {
    return _deque;
}


/* ------------ OTHER METHODS ------------ */

void     PmergeMe::addNumbers( int argc, char **argv ) {
    for (int i = 1; i < argc; i++) {
        std::stringstream   ss(argv[i]);
        int nbr;

        if (!(ss >> nbr) || !ss.eof() || nbr <= 0) {
            throw PmergeMeError("invalid number");
        }
        _vector.push_back(nbr);
        _deque.push_back(nbr);
    }
}





