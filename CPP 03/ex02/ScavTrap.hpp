/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:38:09 by khuynh            #+#    #+#             */
/*   Updated: 2023/07/16 22:52:55 by khuynh           ###   ########.fr       */
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
		Scavtrap(std::string name);
		Scavtrap(Scavtrap const& cpy);
		~Scavtrap();

		Scavtrap& operator=(Scavtrap const& rhs);

		void guardGate();
};

#endif