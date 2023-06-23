/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:42:03 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/23 20:57:36 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harl [ DEBUG|INFO|WARNING|ERROR ]" << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain(av[1]);
	return 0;
}