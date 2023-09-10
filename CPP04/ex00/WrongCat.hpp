/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:06:55 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:15:22 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H

# define WRONGCAT_H

# include "Colors.hpp"
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat( void );
		WrongCat( const WrongCat &oneWrongCat );
		WrongCat & operator=( const WrongCat &oneWrongCat );
		~WrongCat( void );

		void	makeSound( void ) const;
};

#endif
