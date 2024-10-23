
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc <= 2) {
        return (1);
    }

    try {
        PmergeMe    sorter(argc, argv);
        PmergeMe::printNumbers(sorter.getVector(), "Before:  ");
        double vectorTime = sorter.measureTime(sorter.getVector());
        double dequeTime = sorter.measureTime(sorter.getDeque());
        PmergeMe::printNumbers(sorter.getVector(), "After:  ");
        std::cout << std::fixed << std::setprecision(6) << "Time to process a range of     " << sorter.getVector().size() << " elements with std::vector<int> "  << vectorTime << " us\n";
        std::cout << std::fixed << std::setprecision(6) << "Time to process a range of     " << sorter.getDeque().size() << " elements with std::deque<int> "  << dequeTime << " us\n";
    } catch(const PmergeMe::PmergeMeError &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 2;
    }
    return 0;
}