/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 22:49:49 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/29 23:06:30 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	iter(T *adress, int length, void (*ft)(T& var))
{
	for (int i = 0; i < length; i++)
		ft(adress[i]);
}

template<typename T>
void	printer(T &val)
{
	std::cout << val;
}

template<typename T>
void	plusone(T &val)
{
	val = val + 1;
}

int main()
{
	std::cout << "CHAR test" << std::endl;
	char table[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(table, 5, printer<char>);
	std::cout << std::endl;
	std::cout << "INT test" << std::endl;
	int tabler[3] = {0, 1, 2};
	iter(tabler, 3, printer<int>);
	std::cout << std::endl;
	std::cout << "+1 in process...." << std::endl;
	iter(tabler, 3, plusone<int>);
	iter(tabler, 3, printer<int>);
	std::cout << std::endl;
}

