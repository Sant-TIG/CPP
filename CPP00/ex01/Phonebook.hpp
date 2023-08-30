#ifndef PHONEBOOK_H

# define PHONEBOOK_H

# include "Contact.hpp"

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
		int			getNbrContacts ( void );
		int			getCurrContact ( void );
		std::string	getContactFirstName( int i );
		std::string	getContactLastName( int i );
		std::string	getContactNickname( int i );
		std::string	getContactPhoneNumber( int i );
		std::string	getContactSecret( int i );
		std::string truncString( const std::string &str );
		void		addContact( const std::string &fName, const std::string &lName, const std::string &nName, const std::string &phone, const std::string &secret );
		void		showContacts( void );
		void		showOneContact( int i );
};

#endif