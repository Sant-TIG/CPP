#ifndef CONTACT_H

# define CONTACT_H

# include <string>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact(void);
		Contact( const std::string &fName,
				 const std::string &lName,
				 const std::string &nickname,
				 const std::string &phone,
				 const std::string &secret );
		Contact ( const Contact &oneContact );
		Contact & operator=(const Contact &oneContact);
		~Contact( void );
		std::string	getFirstName( void );
		std::string	getLastName( void );
		std::string	getNickname( void );
		std::string getPhoneNumber( void );
		std::string	getSecret( void );
		void		showContact( void );
};

#endif