#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <cstdlib>

void		draw_menu();
int 		processInput( Phonebook &onePhonebook );
std::string	transformCase( const std::string &str, const std::string &type);
void		addNewContact( Phonebook &onePhonebook );
std::string	getInputString( const std::string &query );
void		searchContact( Phonebook &onePhonebook );
int			getInputInt( const std::string &query );

/*
 * Main function of the program. Create a new Phonebook object, then display the menu and process
 * the user's activity in a loop until the user decides to exit the program. After each user interaction
 * it clears the screen and redisplays the menu.
 * Return:
 *     0: when the program ends.
 */
int	main( void ) {
	Phonebook	newPhonebook;
	while (1) {
		draw_menu();
		if (!processInput(newPhonebook)) {
			break;
		}
		system("clear");
	}
	return (0);
}

/*
 * Displays the main menu of the program containing the instructions.
 */
void draw_menu() {
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|               THE PHONEBOOK               |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|               INSTRUCTIONS                |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|  Type one of the following commands:      |" << std::endl;
	std::cout << "|    - ADD: add a new contact               |" << std::endl;
	std::cout << "|    - SEARCH: search for a contact         |" << std::endl;
	std::cout << "|    - EXIT: close the phonebook            |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
}

/*
 * Process the option chosen by the user.
 * Parameters:
 *     onePhonebook: reference to the object where the contact is to be searched for.
 * Return:
 *     0: if the user decides to exit the program.
 *     1: if the user decides to continue or write an invalid option.
 */
int processInput( Phonebook &onePhonebook ) {
	std::string input;
	std::getline(std::cin, input);
	input = transformCase(input, "upper");
	if (input == "ADD") {
		addNewContact(onePhonebook);
		std::cout << onePhonebook.getNbrContacts() << std::endl;
	} else if (input == "SEARCH") {
		searchContact(onePhonebook);
	} else if (input == "EXIT") {
		return 0;
	} else {
		std::cout << "=( Wrong command )=" << std::endl;
	}
	return 1;
}

/*
 * Function to transform a string into upper or lower case. It takes a string and the type
 * of transformation you want to do and returns the transformed string. If the type is
 * incorrect, it does not transform the string.
 * Parameters:
 *     str: string to transform
 *     type: type of transformation
 * Return:
 *     dst: the transformed string or the unchanged string.
 * */
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

/*
 * Add a new contact to the list. Prompts user to enter all items
 * needed to creater the contact. It does not allow the user to leave any
 * field empty.
 * Parameters:
 *     onePhonebook: reference to the object where the contact is to be searched.
 */
void	addNewContact(Phonebook &onePhonebook) {
	std::string firstName = getInputString("Type the first name: ");
	std::string lastName = getInputString("Type the last name: ");
	std::string nickname = getInputString("Type the nickname: ");
	std::string phone = getInputString("Type the phone number: ");
	std::string secret = getInputString("Type the darkest secret: ");
	onePhonebook.addContact(firstName, lastName, nickname, phone, secret);
}

/*
 * Gets a string by console. A string is requested until it is not empty.
 * Parameters:
 *     query: the query message
 * Return:
 *     input: the string entered by the user
 */
std::string	getInputString(const std::string &query) {
	std::string input;
	while (1) {
		std::cout << query << std::endl;
		std::getline(std::cin, input);
		if (!input.empty()) {
			break;
		}		
	}
	return input;
}

/*
 * Search and display the details of a contact in a Phonebook. First show a table
 * with the contacts in the list and then asks the user to choose the index of one of the
 * contacts. He is prompted for this action until he choose a correct one or decide to
 * stop searching.
 * Parameters:
 *     onePhonebook: reference to the object where the contact is to be searched
 */
void	searchContact(Phonebook &onePhonebook) {
	onePhonebook.showContacts();
	int	index;
	while (1) {
		index = getInputInt("Select a contact by typing its index in the phonebook or type 0 to stop searching: ");
		if (index == 0) {
			break;
		} else if (index - 1 < 0 || index > onePhonebook.getNbrContacts()) {
			std::cout << "Index out of range." << std::endl;
		} else {
			onePhonebook.showOneContact(index - 1);
			std::cin.get(); // espera a que el usuario pulse ENTER para dejar de ver el contacto
			break;
		}
	}
}

/*
 * Get an integer by console. A number is requested until a valid one is entered.
 * Parameters:
 *     query: the query message
 * Return:
 *     nbr: the integer entered by the user
 */
int		getInputInt( const std::string &query ) {
	std::string input;
	int			nbr;
	while (1) {
		std::cout << query;
		std::getline(std::cin, input);
		std::istringstream iss(input);
		if (iss >> nbr) {
			return nbr;
		} else {
			std::cout << "Please type an index." << std::endl;
		}
	}
}
