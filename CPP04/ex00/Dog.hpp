/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:41:53 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:06:32 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_H

# define DOG_H

# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog( void );
		Dog( const Dog &oneDog );
		Dog & operator=( const Dog &oneDog );
		~Dog( void );

		void	makeSound( void ) const;
};

#endif
