/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:45:40 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/11 17:14:55 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"
#include "../lib/Dog.hpp"
#include "../lib/WrongCat.hpp"

int	main()
{

	Animal *array[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			array[i] = new Cat();
			array[i]->makeSound();
			std::cout << std::endl;
		}
		else
		{
			array[i] = new Dog();
			array[i]->makeSound();
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete array[i];
	
	std::cout << std::endl;
	
	Dog dog;
    Dog dog2;
    Dog cpy = dog;

    cpy = dog2;

    std::cout << std::endl;
    
    dog.setIdea(0, "I am a dog");
    std::cout << dog.getIdea(0) << std::endl;
    
    std::cout << std::endl;

	Cat cat;
	Cat kitty(cat);
	
	std::cout << std::endl;

	cat.setIdea(0, "I am a cat");
	std::cout << cat.getIdea(0) << std::endl;
	std::cout << std::endl;
	
	return 0;
}