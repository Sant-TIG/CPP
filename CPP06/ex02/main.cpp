#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "utils.hpp"

int	main( void ) {
	Base *p = generate();

	identify(p);
	identify(*p);
	delete p;
	return 0;
}