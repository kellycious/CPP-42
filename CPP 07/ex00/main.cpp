/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:25:04 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/29 22:48:06 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T &min(T &a, T &b)
{
	return (a < b ? a : b);
}

template<typename T>
T &max(T &a, T &b)
{
	return (a > b ? a : b);
}

int main()
{
	std::cout << "input first value: ";
	int a;
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cout << "invalid input" << std::endl;
		return 1;
	}
	std::cout << "input second value: ";
	int b;
	std::cin >> b;
	if (std::cin.fail())
	{
		std::cout << "invalid input" << std::endl;
		return 1;
	}


	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "swapping..." << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;
}