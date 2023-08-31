/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:26:21 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/31 14:26:21 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

/*
 * Program to replace specified lines in a file with a given string.
 */
int	main( int argc, char **argv ) {
	if (argc != 4) {
		std::cout << "ex04: error: invalid number of arguments" << std::endl;
		std::cout << "Usage: ./ex04 <filename> <string> <string>" << std::endl;
		return 1;
	}
	std::string inFile = argv[1];
	std::ifstream	inputFile(inFile.c_str());
	if (inputFile.is_open()) {
		if (inputFile.good()) {
			std::string outFile = inFile + ".replace";
			std::ofstream	outputFile(outFile.c_str());
			if (outputFile.is_open()) {
				std::string	line;
				while (std::getline(inputFile, line)) {
					if (line == (std::string)argv[2]) {
						outputFile << argv[3] << std::endl;
					} else {
						outputFile << line << std::endl;
					}
				}
				outputFile.close();			
			} else {
				std::cout << "Error al abrir el archivo de salida" << std::endl;
			}
		inputFile.close();
		} else {
			std::cout << "ex04: error: error in the input flow" << std::endl;
			return 1;
		}
	} else {
		std::cout << "ex04: error: invalid file" << std::endl;
	}
}
