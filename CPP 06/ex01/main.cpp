/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:44:48 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/29 21:43:17 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *dat = new Data();
	uintptr_t s1;
	Data *s2;

	dat->hello = 42;

	std::cout << "Data : " << dat << std::endl;
	std::cout << "Serialize data..." << std::endl;
	s1 = Serializer::serialize(dat);
	std::cout << "Result : 0x" << std::hex << s1 << std::endl;

	std::cout << "Unserialized data..." << std::endl;
	s2 = Serializer::deserialize(s1);
	std::cout << "Result : " << s2 << std::endl;

	delete dat;
}