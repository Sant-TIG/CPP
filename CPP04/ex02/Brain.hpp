/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:28:31 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:29:09 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H

# define BRAIN_H

# include "Colors.hpp"
# include <string>

class Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain( void );
		Brain( const Brain &oneBrain );
		Brain & operator=( const Brain &oneBrain );
		~Brain( void );
};

#endif
