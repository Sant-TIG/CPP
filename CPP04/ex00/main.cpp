/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:07:16 by sperez-p          #+#    #+#             */
/*   Updated: 2023/09/10 14:15:31 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main( void ) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete(meta);
	delete(j);
	delete(i);
	const WrongAnimal *meta1 = new WrongAnimal();
	const WrongAnimal *i1 = new WrongCat();
	std::cout << i1->getType() << " " << std::endl;
	i1->makeSound(); // will output the wrong animal sound!
	meta1->makeSound();
	delete (meta1);
	delete (i1);
	return 0;
}
