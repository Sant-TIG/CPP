/**
 * @file BitcoinExchange.hpp
 * @author sperez-p  (sperez-p@student.42urduliz.com)
 * @brief  Declaration of the BitcoinExchange class for handling Bitcoin data exchange operations.
 * @date 2024-07-25
 */
#ifndef BITCOINEXCHANGE_H

# define BITCOINEXCHANGE_H

# include "Colors.hpp"

# include <map>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <ctime>

typedef	std::map<std::string, float>			DataMap;
typedef	std::map<std::string, float>::iterator	DataMapIt;

class BitcoinExchange {
	private:
		DataMap	_db_data;

	public:
		BitcoinExchange( void );
		BitcoinExchange( const DataMap &db_data );
		BitcoinExchange( const BitcoinExchange &oneBitcoinExchange );
		BitcoinExchange & operator=( const BitcoinExchange &oneBitcoinExchange );
		~BitcoinExchange( void );

		const DataMap	&getDBData( void ) const;
		void			setDBData( const std::map<std::string, float> &db_data );
		DataMap			readDB( const std::string &db, char delimiter );
		void			validateDBStream( std::ifstream &db );
		void			checkStream( const std::ifstream &content );
		void			validateDBData( const std::string &line, DataMap &data, char delimiter );
		void			showExchange( const std::string &file );
		bool			validateDate( std::string &date, const std::string &line, std::size_t found, const char *format );
		bool			validateValue( float *value, const std::string &line, std::size_t found );

		public:
		class	DBError : public std::exception {
			private:
				std::string	_msg;

			public:
				DBError( const std::string &msg ) throw() : _msg("btc: database_error: " + msg) {}
				~DBError( void ) throw() {}
				virtual const char	*what() const throw() {
					return _msg.c_str();
				}

		};
};

#endif
