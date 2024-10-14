
#ifndef SCALARCONVERSION_H

# define SCALARCONVERSION_H

# include "../incs/Colors.hpp"
//# include <ctype.h>
# include <string>
# include <iostream>
# include <limits.h>
# include <cstdlib>
# include <iomanip>
class ScalarConversion {
	private:
		ScalarConversion(void);
		ScalarConversion(const ScalarConversion &oneScalarConversion);
		ScalarConversion &operator=(const ScalarConversion &oneScalarConversion);
		~ScalarConversion(void);

		static void	charConversion( const char &c );
		static bool	isInt( const std::string &literal );
		static void	intConversion( const int &num );
		static bool	isFloat( const std::string &literal );
		static void	floatConversion( const float &num );
		static bool isDouble( const std::string &literal );
		static void	doubleConversion( const double &num );
		static bool	pseudoDoubleConversion( const std::string &literal );
		static bool pseudoFloatConversion( const std::string &literal );

	public:
		static int	convert( const std::string &literal );
};

#endif