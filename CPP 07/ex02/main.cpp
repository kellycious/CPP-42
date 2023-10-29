/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:23:44 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/30 00:05:29 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	std::cout << "Enter array size : ";
	unsigned int n;
	std::cin >> n;
	if (std::cin.fail())
		return (std::cout << "invalid input" << std::endl, 1);
	Array<int> example(n);
	std::cout << std::endl;
	std::cout << "Creating an array of size " << n << " ..." << std::endl;
	
	for (unsigned int i = 0; i < n; i++)
	{
		try 
		{	std::cout << "array[" << i << "] = " << example[i] << std::endl;}
		catch(const std::exception &e)
		{	std::cerr << e.what() << std::endl;}
	}
	std::cout << std::endl;
	std::cout << "Fill array...." << std::endl;
	for (unsigned int i = 0; i < n; i++)
	{
		unsigned int a;
		std::cout << "Enter array[" << i << "] = ";
		std::cin >> a;
		if (std::cin.fail())
			return (std::cout << "invalid input" << std::endl, 1);
		example[i] = a;
	}
	std::cout << std::endl;
	std::cout << "Filled array" << std::endl;
	for (unsigned int i = 0; i < n; i++)
	{
		try 
		{	std::cout << "array[" << i << "] = " << example[i] << std::endl;}
		catch(const std::exception &e)
		{	std::cerr << e.what() << std::endl;}
	}
	}