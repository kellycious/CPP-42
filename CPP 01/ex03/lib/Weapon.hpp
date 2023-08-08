/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:35:25 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/08 16:39:55 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	private:
		std::string type;
		
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		std::string const &getType(void);
		void	setType(std::string type);
};

#endif