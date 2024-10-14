/**
 * @file BitcoinExchange.cpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief Implementation of the BitcoinExchange class for handling Bitcoin data exchange operations.
 * @date 2024-07-25
 */

#include "BitcoinExchange.hpp"
#include <iomanip>

/* ------------ CONSTRUCTORS AND DESTRUCTOR ------------ */

/**
 * @brief Construct a new BitcoinExchange object with default values.
 */
BitcoinExchange::BitcoinExchange( void ) : _db_data(readDB("data/data.csv", ',')) {
	std::cout << GREEN << "BitcoinExchange default constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new BitcoinExchange object with the values passed as parameters.
 *
 * @param db_data A reference to a map containing the initial database data.
 */
BitcoinExchange::BitcoinExchange( const DataMap &db_data ) : _db_data(db_data) {
	std::cout << GREEN << "BitcoinExchange parameterized constructor called" << RESET << std::endl;
}

/**
 * @brief Construct a new BitcoinExchange object by copying the values from another object.
 *
 * @param oneBitcoinExchange A reference to the BitcoinExchange object to be copied.
 */
BitcoinExchange::BitcoinExchange( const BitcoinExchange &oneBitcoinExchange ) {
	*this = oneBitcoinExchange;
	std::cout << GREEN << "BitcoinExchange copy constructor called" << RESET << std::endl;
}

/**
 * @brief Destroy the BitcoinExchange object.
 */
BitcoinExchange::~BitcoinExchange( void ) {
	std::cout << RED << "BitcoinExchange destructor called" << RESET << std::endl;
}


/* ------------ OVERLOAD METHODS ------------ */

/**
 * @brief Overloads the assignment operator for the BitcoinExchange class.
 *
 * @param oneBitcoinExchange The source BitcoinExchange object to assign from.
 * @return BitcoinExchange& A reference to the current BitcoinExchange object after assignment.
 */
BitcoinExchange & BitcoinExchange::operator=( const BitcoinExchange &oneBitcoinExchange ) {
	if (this != &oneBitcoinExchange) {
		_db_data = oneBitcoinExchange.getDBData();
	}
	return *this;
}


/* ------------ GETTER METHODS ------------ */

/**
 * @brief Retrieves the database data.
 *
 * @return const DataMap& A constant reference to the internal data map.
 */
const DataMap	&BitcoinExchange::getDBData( void ) const {
	return _db_data;
}


/* ------------ SETTER METHODS ------------ */

/**
 * @brief Sets the database data.
 * 
 * @param db_data A reference to a map containing the new database data.
 */
void	BitcoinExchange::setDBData( const std::map<std::string, float> &db_data ) {
	_db_data = db_data;
}


/* ------------ OTHER METHODS ------------ */

/**
 * @brief Reads and parses the database file.
 *
 * Reads the content of the specified database file, parsing each line into a data map. It validates the stream and 
 * each line's format, ensuring that the data is correctly structured
 *
 * @param db The path to the database file.
 * @param delimiter The character used to delimit the data fields in the file.
 * @return DataMap The parsed data map containing the database data.
 * @throws DBError If the database file is empty or cannot be read properly.
 */
DataMap	BitcoinExchange::readDB( const std::string &db, char delimiter ) {
	std::ifstream	db_content(db.c_str());
	validateDBStream(db_content);

	std::string	line;
	DataMap		db_data;
	while (std::getline(db_content, line)) {
		validateDBData(line, db_data, delimiter);
	}
	checkStream(db_content);
	if (db_data.empty()) {
		throw DBError("the database is empty.");
	}
	return db_data;
}

/**
 * @brief Validates the database file stream.
 *
 * Checks if the database file stream is open and readable. Additionally, it reads the first line to ensure
 * the stream is in a good state and calls checkStream to handle any errors that might occur during this initial read.
 *
 * @param db A reference to the ifstream object representing the database file stream.
 * @throws DBError If the database file cannot be opened or read properly.
 */
void	BitcoinExchange::validateDBStream( std::ifstream &db ) {
	if (!db.is_open()) {
		throw DBError("could not open the database");
	}

	std::string	line;
	if (!std::getline(db, line)) {
		checkStream(db);
	}
}

/**
 * @brief Checks the state of the file stream.
 *
 * This method performs checks on the provided file stream to determine if there have been
 * any errors during reading. It first checks if an error occurred before reaching the end
 * of the file, then it checks the final state of the stream after reading.
 *
 * @param content A constant reference to the ifstream object representing the file stream.
 * @throws DBError If an I/O or logical error occurs while reading the database file, or if the end of the file cannot be read properly.
 */
void	BitcoinExchange::checkStream( const std::ifstream &content ) {
	if (!content.eof()) {
		if (content.bad()) {
			throw DBError("I/O error while reading the database file.");
		} else if (content.fail()) {
			throw DBError("logical error while reading the database file.");
		}		
	} else if (content.bad()) {
		throw DBError("failed to read the end of the database file.");
	}
}

/**
 * @brief Validates and parses a line of database data.
 *
 * Parses the line using the specified delimiter, and validates the format. It extracts the date 
 * and Bitcoin price, storing them in the provided data map.
 *
 * @param line A constant reference to the string representing a line from the database file.
 * @param data A reference to the DataMap where the parsed data will be stored.
 * @param delimiter The character used to delimit the data fields in the line.
 * @throws DBError If the line does not contain the delimiter or if the input is otherwise invalid.
 */
void	BitcoinExchange::validateDBData( const std::string &line, DataMap &data, char delimiter ) {
	std::size_t	found;
	std::string	date;
	float		btc_price;

	found = line.find(delimiter);
	if (found != std::string::npos) {
		date = line.substr(0, found);
		btc_price = strtof(line.substr(found + 1, line.size()).c_str(), NULL);
		data.insert(make_pair(date, btc_price));
	} else {
		throw DBError("bad input => " + line);
	}
}

/**
 * @brief Displays the Bitcoin exchange values from a file.
 *
 * This method reads a file containing exchange data, validates each line, and computes
 * the exchange values based on the internal database data.
 *
 * @param file The path to the file containing the exchange data.
 * @throws DBError If the database file cannot be opened or read properly.
 */
void	BitcoinExchange::showExchange( const std::string &file ) {
	std::ifstream	file_content(file.c_str());
	validateDBStream(file_content);

	std::string	line;
	std::size_t found;
	std::string date;
	float value;
	DataMapIt	lower;
	while (std::getline(file_content, line)) {
		found = line.find('|');
		if (found != std::string::npos) {
			if (!validateDate(date, line, found, "%Y-%m-%d") || !validateValue(&value, line, found)) {
				continue;			
			}
			lower = _db_data.lower_bound(date);
			if (lower->first != date) {
				lower--;
			}
			std::cout << date << " => " << value << " = " << lower->second * value << std::endl;
		} else {
			std::cerr << ("Error: bad input => " + line) << std::endl;
		}
	}
}

/**
 * @brief Validates and parses a date from a string.
 *
 * This method extracts a date substring from the provided line, starting from the beginning
 * of the line up to the specified position. It then attempts to parse this substring into a
 * `tm` structure using the provided date format.
 *
 * @param date A reference to a string where the parsed date will be stored.
 * @param line The string from which the date will be extracted.
 * @param found The position in the string where the date extraction should end (usually just before a delimiter).
 * @param format The date format to be used for parsing the date (e.g., "%Y-%m-%d").
 * @return `true` if the extracted date is valid according to the provided format,
 *         `false` otherwise.
 */
bool	BitcoinExchange::validateDate( std::string &date, const std::string &line, std::size_t found, const char *format ) {
	struct tm	time;

	date = line.substr(0, found - 1);
	if (!strptime(date.c_str(), format, &time)) {
		std::cerr << "Error: date is invalid." << std::endl;
		return false;
	}
	return true;
}

/**
 * @brief Validates and parses a floating-point value from a string.
 *
 * This method extracts a floating-point and validates the value to ensure it is within the acceptable range.
 *
 * @param value A pointer to a float where the parsed value will be stored.
 * @param line The string from which the value will be extracted.
 * @param found The position in the string where the extraction should begin (typically just after a delimiter).
 * @return true if the extracted value is valid (positive and less than or equal to 1000), false otherwise.
 */
bool	BitcoinExchange::validateValue( float *value, const std::string &line, std::size_t found ) {
	*value = strtof(line.substr(found + 1, line.size()).c_str(), NULL);
	if (*value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	} else if (*value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}