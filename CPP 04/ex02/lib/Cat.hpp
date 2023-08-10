/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:49:16 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 16:44:20 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
	private:
		Brain *brain;
		
	public:
		Cat();
		Cat(const Cat &cpy);
		~Cat();

		Cat& operator=(const Cat &cpy);

		void makeSound() const;
		std::string getIdea(int i) const;
		std::string setIdea(int i, std::string idea);
};

#endif 