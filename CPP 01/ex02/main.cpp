/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:20:00 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 23:25:22 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string intro = "HI THIS IS BRAIN";
	std::string *ptr = &intro;
	std::string &ref = intro;

	std::cout << "Memory of the string: " << &intro << std::endl;
	std::cout << "Memory of the pointer: " << ptr << std::endl;
	std::cout << "Memory of the reference: " << &ref << std::endl;

	std::cout << std::endl;

	std::cout << "Value of the string: " << intro << std::endl;
	std::cout << "Value of the pointer: " << *ptr << std::endl;
	std::cout << "Value of the reference: " << ref << std::endl;

	return 0;
}