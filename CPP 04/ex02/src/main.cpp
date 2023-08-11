/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:45:40 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/11 15:24:33 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cat.hpp"
#include "../lib/Dog.hpp"
#include "../lib/WrongCat.hpp"

int main()
{
    const Animal* meta[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2)
            meta[i] = new Dog();
        else
            meta[i] = new Cat();
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        meta[i]->makeSound();
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
        delete meta[i];

    // Animal blubla;
    // Animal *tmp = new Animal();
    return 0;
}