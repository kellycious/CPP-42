/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:45:40 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 00:06:31 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"
#include "../lib/Dog.hpp"
#include "../lib/WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *k = new WrongCat();

	std::cout << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;

	std::cout << std::endl;
	
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;

	return 0;
}