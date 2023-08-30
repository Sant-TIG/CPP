#include <iostream>
#include <string>
#include <cctype>

std::string	transformCase( const std::string &str, const std::string &type );

/*
 *
 */
int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		std::cout << transformCase(argv[i], "upper");
	}
	std::cout << std::endl;
	return 1;
}


/*
 * Transforms a string to uppercase or lowercase depending on the value of type,
 * passed as a parameter. If the type is wrong, it returns the original string.
 * Parameters:
 *     str: the string to transform
 *     type: the type of transformation
 * Return:
 *     dst: the string tranformed
 */
std::string transformCase(const std::string &str, const std::string &type) {
	std::string dst;
	std::size_t len = str.length();

	dst.reserve(len);
	const std::locale loc;
	if (type == "upper") {
		for (std::size_t i = 0; i < len; i++) {
			dst += std::toupper(str[i], loc);
		}		
	} else if (type == "lower") {
		for (std::size_t i = 0; i < len; i++) {
			dst += std::tolower(str[i], loc);
		}
	} else {
		return str;
	}
	return dst;
}