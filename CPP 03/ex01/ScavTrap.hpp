/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:38:09 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/09 15:29:26 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class Scavtrap : public ClapTrap
{		
	public:
		Scavtrap();
		Scavtrap(std::string const& name);
		Scavtrap(Scavtrap const& cpy);
		~Scavtrap();

		Scavtrap& operator=(Scavtrap const& rhs);

		void guardGate();
		void attack(const std::string& target);
};

#endif