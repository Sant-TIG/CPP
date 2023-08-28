#include <iostream>
#include <string>
#include <cctype>

std::string	transformCase( const std::string &str, const std::string &type );

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
	reserve(): asigna el espacio en el bufer interno de la cadena para no
			   realojarla repetidamente. No utiliza memoria dinamica.
	locale: crear contexto de localizacion regional para el manejo de 
			caracteres especiales.
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