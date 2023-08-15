/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:47:42 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/15 16:00:03 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
	private:
		Brain *brain;
		
	public:
		Dog();
		Dog(const Dog &cpy);
		~Dog();

		Dog& operator=(const Dog &cpy);

		void	makeSound() const;
		Brain*	getBrain() const;
		
};

#endif 