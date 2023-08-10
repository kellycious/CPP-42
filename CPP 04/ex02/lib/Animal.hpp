/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:46:11 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 17:37:06 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &cpy);
		virtual ~Animal();

		Animal& operator=(const Animal &cpy);

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif