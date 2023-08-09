/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:49:16 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 23:29:26 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal 
{
	public:
		Cat();
		Cat(const Cat &cpy);
		~Cat();

		Cat& operator=(const Cat &cpy);

		void	makeSound() const;
		std::string	getType() const;
};

#endif 