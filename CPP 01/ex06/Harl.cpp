/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:42:46 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/23 20:55:00 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "\033[32m[DEBUG]\033[0m" << std::endl;
}

void Harl::info(void)
{
	std::cout << "\033[34m[INFO]\033[0m" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\033[33m[WARNING]\033[0m" << std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[1m\033[31m[ERROR]\033[0m" << std::endl;
}

int  Lvl(std::string &level)
{
    std::string lvl[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    for (int i = 0; i< 4; ++i)
        if (lvl[i] == level)
            return (i);
    return (-1);
}

void Harl::complain(std::string level)
{
	int	i = Lvl(level);
	switch(i)
	{
		case 0:
			debug();
			break;
		case 1:
			info();
			break;
		case 2:
			warning();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[Probably complaining about insignificant problems]" << std::endl;
			break;
	}
}