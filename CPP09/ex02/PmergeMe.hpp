/**
 * @file PmergeMe.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Header file for the PmergeMe class, which evaluates expressions in Reverse Polish Notation.
 * @date 2024-07-29
 */

#ifndef PMERGME_HPP

# define PMERGME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <sys/time.h>
# include <cstdlib>
# include <algorithm>
# include <iomanip>
# include <ctime>

# include "../incs/Colors.hpp"

typedef	std::vector<int>	Vector;
typedef std::deque<int>     Deque;

class PmergeMe {
	private:
        Vector  _vector;
        Deque   _deque;

	public:
		PmergeMe( void );
        PmergeMe( int argc, char **argv );
		PmergeMe( const PmergeMe &other );
		~PmergeMe( void );

		PmergeMe & operator=( const PmergeMe &other );

        Vector    &getVector( void );
        Deque     &getDeque( void );

        void	addNumbers( int argc, char **argv );

        template<typename T>
        static void printNumbers( const T &container, const std::string &msg ) {
            std::cout << msg;
            for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }	

        template<typename T>
        double    measureTime( T &container ) {
            struct timeval start, ends;

            gettimeofday(&start, NULL);
			mergeInsertSort(container);
            gettimeofday(&ends, NULL);
            double elapsed_time = (ends.tv_sec - start.tv_sec) + (ends.tv_usec - start.tv_usec) / 1000000.0;
			return elapsed_time;
        }

        template<typename T>
        void    mergeInsertSort( T &container ) {
			if (container.size() <= 10) {
					for (std::size_t i = 1; i < container.size(); ++i) {
						int key = container[i];
						std::size_t j = i;
						while (j > 0 && container[j - 1] > key) {
							container[j] = container[j - 1];
							--j;
						}
						container[j] = key;
					}
				} else {
					std::size_t middle = container.size() / 2;
					T left(container.begin(), container.begin() + middle);
					T right(container.begin() + middle, container.end());

					mergeInsertSort(left);
					mergeInsertSort(right);

					std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
				}
			}

	public:
		/**
		 * @class PmergeMeError
		 * @brief Exception class for errors related to stack operations.
		 */
		class	PmergeMeError : public std::exception {
			private:
				std::string _msg; ///< Error message.

			public:
				/**
				 * @brief Constructor for the PmergeMeError class.
				 * @param msg The error message.
				 */
				PmergeMeError( const std::string &msg ) throw() : _msg("PmergeMe: stack_error: " + msg) {}
				/**
				 * @brief Destructor for the PmergeMeError class.
				 */
				~PmergeMeError( void ) throw() {}
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
