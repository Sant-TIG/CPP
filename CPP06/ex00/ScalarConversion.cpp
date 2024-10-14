
#include "ScalarConversion.hpp"

/*
 * Default constructor. Initializes instance variables to 0.
 */
ScalarConversion::ScalarConversion( void ) {
	std::cout << GREEN << "ScalarConversion default constructor called" << RESET << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
ScalarConversion::ScalarConversion( const ScalarConversion &oneScalarConversion ) {
	*this = oneScalarConversion;
	std::cout << GREEN << "ScalarConversion copy constructor called" << RESET << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
ScalarConversion & ScalarConversion::operator=( const ScalarConversion &oneScalarConversion ) {
	if (this != &oneScalarConversion) {
		return (ScalarConversion &)oneScalarConversion;
	}
	return *this;
}

/*
 * Destructor.
 */
ScalarConversion::~ScalarConversion( void ) {
	std::cout << RED << "ScalarConversion destructor called" << RESET << std::endl;
}

/*******************************CHAR CONVERSION*************************************/

void	ScalarConversion::charConversion( const char &c ) {
		if (isprint(c)) {
			std::cout << "char: '" << c << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}


/*******************************INT CONVERSION**************************************/

void	ScalarConversion::intConversion( const int &num ) {
	char	c = static_cast<char>(num);
	if (!isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

bool	ScalarConversion::isInt( const std::string &literal ) {
	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+') {
		i++;
	}
	while (i < literal.length()) {
		if (!isdigit(literal[i])) {
			return false;
		}
		i++;
	}
	double	num = atof(literal.c_str());
	if (num > INT_MAX || num < INT_MIN) {
		return false;
	}
	return true;
}


/*******************************FLOAT CONVERSION************************************/

bool	ScalarConversion::pseudoFloatConversion( const std::string &literal ) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
		return true;
	}
	return false;
}

bool	ScalarConversion::isFloat( const std::string &literal ) {
	size_t	i = 0;

	if (pseudoFloatConversion(literal)) {
		return false;
	}
	
	if (literal[0] == '-' || literal[0] == '+') {
		i++;
	}
	while (literal[i] && literal[i] != '.') {
		if (!isdigit(literal[i])) {
			return false;
		}
		i++;
	}
	if (literal[i] == '.') {
		i++;
	}
	if (!isdigit(literal[i])) {
		return false;
	}
	while (literal[i] && literal[i] != 'f') {
		if (!isdigit(literal[i])) {
			return false;
		}
		i++;
	}
	return literal[i] == 'f';
}

void	ScalarConversion::floatConversion( const float &num ) {
	char	c = static_cast<char>(num);
	if (!isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	if (num > INT_MAX|| num < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}
    if (num == static_cast<int>(num)) {  // Verifica si es un entero exacto
        std::cout << "float: " << num << ".0f" << std::endl;
    } else {
        std::cout << "float: " << num << "f" << std::endl;
    }
    if (static_cast<double>(num) == static_cast<int>(num)) {
        std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
    } else {
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
}

/******************************DOUBLE CONVERSION************************************/

bool	ScalarConversion::pseudoDoubleConversion( const std::string &literal ) {
	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return true;
	}
	return false;
}

bool	ScalarConversion::isDouble( const std::string &literal ) {
	size_t	i = 0;

	if (pseudoDoubleConversion(literal)) {
		return false;
	}
	if (literal[0] == '-' || literal[0] == '+') {
		i++;
	}
	while (literal[i] && literal[i] != '.') {
		if (!isdigit(literal[i])) {
			return false;
		}
		i++;
	}
	if (!isdigit(literal[++i])) {
		return false;
	}
	while (literal[i]) {
		if (!isdigit(literal[i])) {
			return false;
		}
		i++;
	}
	return true;
}

void	ScalarConversion::doubleConversion( const double &num ) {
	char	c = static_cast<char>(num);
	if (!isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	if (num > INT_MAX|| num < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}
	if (num == static_cast<int>(num)) {  // Verifica si es un entero exacto
        std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    }
    if (static_cast<double>(num) == static_cast<int>(num)) {
        std::cout << "double: " << num << ".0" << std::endl;
    } else {
        std::cout << "double: " << num << std::endl;
    }	
}

/***********************************************************************************/



int ScalarConversion::convert( const std::string &literal ) {
	if (literal.length() == 1 && !isdigit(literal[0])) {
		charConversion(literal[0]);
	} else if (isInt(literal)) {
		intConversion(atoi(literal.c_str()));
	} else if (isFloat(literal)) {
		floatConversion(static_cast<float>(atof(literal.c_str())));
	} else if (isDouble(literal)) {
		doubleConversion(atof(literal.c_str()));
	} else {

	}
	return 0;
}