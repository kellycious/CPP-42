/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:37:53 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/04 02:36:46 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iostream>

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_nb;
		std::string darkest_secret;

	public:
		Contact (void);
		~Contact (void);
		std::string input_fn(void);
		std::string input_ln(void);
		std::string input_nickname(void);
		std::string input_nb(void);
		std::string input_dsecret(void);
		void		input_contact(void);
};

class	Phonebook
{
	private:
		Contact contact[8];
		int		index;
	
	public:
		Phonebook(void);
		~Phonebook(void);
		void	add_contact(Phonebook *phonebook);
		int		search_contact(Phonebook *phonebook);
};

#endif