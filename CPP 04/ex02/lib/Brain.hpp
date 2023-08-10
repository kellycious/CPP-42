/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 00:07:58 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 17:19:44 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &cpy);
		~Brain();

		Brain &operator=(const Brain &cpy);
		
		std::string getIdea(int i) const;
		std::string setIdea(int i, std::string idea);
		
};

#endif