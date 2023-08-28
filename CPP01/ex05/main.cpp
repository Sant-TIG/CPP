#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	oneHarl;

	if (argc == 2) {
		oneHarl.complain(argv[1]);
	}
	return (0);
}