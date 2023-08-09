/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:47:42 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 00:04:53 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal 
{
	public:
		Dog();
		Dog(const Dog &cpy);
		~Dog();

		Dog& operator=(const Dog &cpy);

		void	makeSound() const;
};

#endif 