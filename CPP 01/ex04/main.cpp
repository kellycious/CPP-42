/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:25:51 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/04 20:53:11 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replacer(std::string &str, std::string const &s1, std::string const &s2)
{
	size_t pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str = str.substr(0, pos) + s2 + str.substr(pos + s1.length());
		pos += s2.length();
	}
}

int	main(int ac, char **av)
{
	if (ac < 4)
		return (std::cout << "Missing arguments" << std::endl, 0);
	if (ac > 4)
		return (std::cout << "Too many arguments" << std::endl, 0);
	
	std::ifstream inputfile(av[1]);
	std::ofstream outputfile;
	outputfile.open((av[1] + std::string(".replace")).c_str());
	inputfile.open(av[1]);
	
	if (!inputfile.is_open() || !outputfile.is_open())
		return (std::cout << "File does not exist" << std::endl, 0);
	
	std::string buffy((std::istreambuf_iterator<char>(inputfile)), (std::istreambuf_iterator<char>()));
	replacer(buffy, av[2], av[3]);
	outputfile << buffy;
	inputfile.close();
	outputfile.close();
}