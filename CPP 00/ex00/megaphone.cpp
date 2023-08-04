/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:47:15 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/04 19:47:16 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **av)
{
	if (ac < 2)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);

	std::string str;
	for (int i = 1; i < ac; ++i)
	{	
		str += av[i];
		if (i < ac - 1)
			str += " ";
	}
	for (std::string::iterator c = str.begin(); c != str.end(); c++)
		*c = std::toupper(*c);
	std::cout << str << std::endl;
	return (0);
}
