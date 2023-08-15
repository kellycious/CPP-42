/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:49:16 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 23:29:26 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
	public:
		WrongCat();
		WrongCat(const WrongCat &cpy);
		~WrongCat();

		WrongCat& operator=(const WrongCat &cpy);

		void makeSound() const;

};

#endif 