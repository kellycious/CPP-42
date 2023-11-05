/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:53:07 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/05 18:59:51 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "------------ TEST 1 : WORKING ------------" << std::endl;
	Span array(10);

	try
	{
		array.addNumber(14);
		array.addNumber(4);
		array.addNumber(100);
		array.addNumber(50);

		std::cout << "Longest span: " << array.longestSpan() << std::endl;
		std::cout << "Shortest span: " << array.shortestSpan() << std::endl;
	}
	catch(const std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "------------ TEST 2 : CAN'T ADD NUMBER ------------" << std::endl;
	Span array2(1);

	try
	{
		array2.addNumber(14);
		array2.addNumber(4);
	}
	catch(const std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "------------ TEST 3 : ARRAY TOO SMALL OR EMPTY  ------------" << std::endl;
	Span array3(2);

	try
	{
		array3.addNumber(14);
		std::cout << "Longest span: " << array3.longestSpan() << std::endl;		
	}
	catch(const std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "------------ TEST 4 : BETTER ADD ------------" << std::endl;
	Span	array4(1000);

	try
	{
		std::vector<int> Barray;
		for (int i = 0; i < 100; ++i)
			Barray.push_back(i);
		
		array4.betterAdd(Barray.begin(), Barray.end());

		std::cout << "Longest span: " << array4.longestSpan() << std::endl;
		std::cout << "Shortest span: " << array4.shortestSpan() << std::endl;
	}
	catch(const std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}