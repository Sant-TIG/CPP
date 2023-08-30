/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:53:34 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 14:53:36 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int	Phonebook::nbrContacts = 0;
int	Phonebook::currContact = 0;

/*
 * Default constructor. Initializes instance variables to 0.
 */
Phonebook::Phonebook( void ) {
	std::cout << "Phonebook default constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Phonebook::Phonebook( const Phonebook &onePhonebook ) {
	*this = onePhonebook;
	std::cout << "Phonebook copy constructor called" << std::endl;
}

/*
 * Overloading of the assignment operator.
 */
Phonebook & Phonebook::operator=( const Phonebook &onePhonebook ) {
	if (this != &onePhonebook) {
		nbrContacts = onePhonebook.nbrContacts;
		currContact = onePhonebook.currContact;
        for (int i = 0; i < MAX_CONTACTS; ++i) {
            contacts[i] = onePhonebook.contacts[i];
        }
    }
    return *this;
}

/*
 * Destructor
 */
Phonebook::~Phonebook( void ) {
	std::cout << "Phonebook destructor called" << std::endl;
}

/*
 * Getter methods
 */
int	Phonebook::getNbrContacts( void ) const {
	return nbrContacts;
}

int	Phonebook::getCurrContact( void ) const {
	return currContact;
}

std::string	Phonebook::getContactFirstName( int i ) const {
	return truncString(contacts[i].getFirstName());
}

std::string	Phonebook::getContactLastName( int i ) const {
	return truncString(contacts[i].getLastName());
}

std::string	Phonebook::getContactNickname( int i ) const {
	return truncString(contacts[i].getNickname());
}

std::string	Phonebook::getContactPhoneNumber( int i ) const {
	return truncString(contacts[i].getPhoneNumber());
}

std::string	Phonebook::getContactSecret( int i ) const {
	return truncString(contacts[i].getSecret());
}

/*
 * Truncates a given string if its length is more than 10 characters.
 * Parameters:
 *     str: the string to be truncated
 * Return:
 *     A modified version if the input string, either truncated or unchanged.
 */
std::string Phonebook::truncString( const std::string &str ) const {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

/*
 * Adds a new contact to the Phonebook. If the maximum number of contacts is reached, its overwrites the oldest
 * contact.
 * Parameters:
 *     fName: first name of the contact
 *     lName: last name of the contact
 *     nName: nickname of the contact
 *     phone: phone number of the contact
 *     secret: a secret associated with the contact
 */
void	Phonebook::addContact( const std::string &fName, const std::string &lName, const std::string &nName, const std::string &phone, const std::string &secret )
{
	Contact	newContact(fName, lName, nName, phone, secret);
	if (currContact == MAX_CONTACTS) {
		currContact = 0;
	}
	contacts[currContact] = newContact;
	currContact++;
	if (nbrContacts < MAX_CONTACTS) {
		nbrContacts++;
	}
}

/*
 * Shows the information of all contacts.
 */
void	Phonebook::showContacts( void ) const {
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < nbrContacts; i++) {
		std::cout << "|" << std::setw(10) << std::right << i + 1;
		std::cout << "|" << std::setw(10) << std::right << getContactFirstName(i);
		std::cout << "|" << std::setw(10) << std::right << getContactLastName(i);
		std::cout << "|" << std::setw(10) << std::right << getContactNickname(i);
		std::cout << "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
}

/*
 * Show the information of one contact.
 */
void	Phonebook::showOneContact( int i ) const {
	contacts[i].showContact();
}
