/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:37:53 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/19 17:14:08 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include "Contact.hpp"

class	Phonebook
{
	private:
		Contact contact[8];
		int		index;
	
	public:
		Phonebook(void);
		~Phonebook(void);
		void	displayer(std::string str);
		void	add_contact(Phonebook *phonebook);
		int		search_contact(Phonebook *phonebook);
};

#endif