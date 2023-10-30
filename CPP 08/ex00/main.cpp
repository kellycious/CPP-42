/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:49:17 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/30 22:43:06 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main ()
{

	std::cout << "Vector test: 10 - 14 - 20" << std::endl;

	std::vector <int> numbers;
	
	numbers.push_back(10);
	numbers.push_back(14);
	numbers.push_back(20);
	
	bool exception = false;
	
	std::cout << "Is there a 14 ?" << std::endl;
	
	try 
	{
		easyfind(numbers, 14);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exception = true;
	}

	if (!exception)
		std::cout << "Yes ! :)" << std::endl;

	std::cout << "Is there a 0 ?" << std::endl;
	
	try 
	{
		easyfind(numbers, 0);
		exception = false;
	}
	catch(const std::exception &e)
	{
		return (std::cerr << e.what() << std::endl, 1);
	}
	if (!exception)
		std::cout << "Yes ! :)" << std::endl;

}