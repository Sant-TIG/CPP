/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:45:01 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 14:45:10 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
 * Default constructor. Initializes instance variables to 0.
 */
Contact::Contact( void ) : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {
	std::cout << "Contact default constructor called" << std::endl;
}

/*
 * Parameterized constructor. Initializes the instance variables with the values passed as parameters.
 */
Contact::Contact( const std::string &fName, const std::string &lName, const std::string &nName, const std::string &phone, const std::string &secret )
				  : firstName(fName), lastName(lName), nickname(nName), phoneNumber(phone), darkestSecret(secret) {
	std::cout << "Contact parameterized constructor called" << std::endl;
}

/*
 * Copy constructor. Initializes instance variables with the values of another object.
 */
Contact::Contact( const Contact &oneContact ) {
	*this = oneContact;
	std::cout << "Contact copy constructor called" << std::endl;	
}

/*
 * Overloading of the assignment operator.
 */
Contact & Contact::operator=( const Contact& oneContact ) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &oneContact) {
		firstName = oneContact.firstName;
		lastName = oneContact.lastName;
		nickname = oneContact.nickname;
		phoneNumber = oneContact.phoneNumber;
		darkestSecret = oneContact.darkestSecret;
	}
	return *this;
}

/*
 * Destructor.
 */
Contact::~Contact( void ) {
	std::cout << "Contact destructor called" << std::endl;
}

/*
 * Getter methods
 */
std::string	Contact::getFirstName( void ) const {
	return	firstName;
}

std::string	Contact::getLastName( void ) const {
	return lastName;
}

std::string	Contact::getNickname( void ) const {
	return nickname;
}

std::string	Contact::getPhoneNumber( void ) const {
	return phoneNumber;
}

std::string	Contact::getSecret( void ) const {
	return darkestSecret;
}

/*
 * Shows the information of a contact
 */
void	Contact::showContact( void ) const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
