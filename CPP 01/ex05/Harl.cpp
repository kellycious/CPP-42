/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:42:46 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/23 20:40:20 by khuynh           ###   ########.fr       */
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

void Harl::complain(std::string lvl)
{
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (lvls[i] == lvl)
			(this->*f[i])();
	}
}