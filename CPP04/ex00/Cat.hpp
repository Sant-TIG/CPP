/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:41:40 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 13:52:13 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H

# define CAT_H

# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat( void );
		Cat( const Cat &oneCat );
		Cat & operator=( const Cat &oneCat );
		~Cat( void );

		void	makeSound() const;
};

#endif
