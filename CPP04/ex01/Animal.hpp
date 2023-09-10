/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:41:19 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:28:15 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H

# define ANIMAL_H

# include "Colors.hpp"
# include <string>

class Animal {
	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( const std::string &type );
		Animal( const Animal &oneAnimal );
		Animal & operator=( const Animal &oneAnimal );
		virtual ~Animal( void );

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
};

#endif
