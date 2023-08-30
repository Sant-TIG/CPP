/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:50:37 by sperez-p          #+#    #+#             */
/*   Updated: 2023/08/30 14:50:59 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H

# define CONTACT_H

# include <string>
# include <iostream>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact( void );
		Contact( const std::string &fName,
				 const std::string &lName,
				 const std::string &nickname,
				 const std::string &phone,
				 const std::string &secret );
		Contact ( const Contact &oneContact );
		Contact & operator=(const Contact &oneContact);
		~Contact( void );
		std::string	getFirstName( void ) const;
		std::string	getLastName( void ) const;
		std::string	getNickname( void ) const;
		std::string	getPhoneNumber( void ) const;
		std::string	getSecret( void ) const;
		void		showContact( void ) const;
};

#endif
