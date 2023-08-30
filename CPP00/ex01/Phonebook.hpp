/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:53:41 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 14:53:42 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H

# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>

class Phonebook {
	private:
		static const int	MAX_CONTACTS = 8;
		Contact				contacts[MAX_CONTACTS];
		static int			nbrContacts;
		static int			currContact;

	public:
		Phonebook( void );
		Phonebook( const Phonebook &onePhonebook );
		Phonebook & operator=( const Phonebook &onePhonebook );
		~Phonebook( void );
		int			getNbrContacts ( void ) const;
		int			getCurrContact ( void ) const;
		std::string	getContactFirstName( int i ) const;
		std::string	getContactLastName( int i ) const;
		std::string	getContactNickname( int i ) const;
		std::string	getContactPhoneNumber( int i ) const;
		std::string	getContactSecret( int i ) const;
		std::string truncString( const std::string &str ) const;
		void		addContact( const std::string &fName, const std::string &lName,
								const std::string &nName, const std::string &phone,
								const std::string &secret );
		void		showContacts( void ) const;
		void		showOneContact( int i ) const;
};

#endif
