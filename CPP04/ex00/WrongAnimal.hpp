/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:06:44 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:15:10 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H

# define WRONGANIMAL_H

# include "Colors.hpp"
# include <string>

class WrongAnimal {
	protected:
		std::string	_type;

	public:
		WrongAnimal( void );
		WrongAnimal( const std::string &type );
		WrongAnimal( const WrongAnimal &oneWrongAnimal );
		WrongAnimal & operator=( const WrongAnimal &oneWrongAnimal );
		virtual ~WrongAnimal( void );

		std::string	getType( void ) const;
		void		makeSound( void ) const;
};

#endif
