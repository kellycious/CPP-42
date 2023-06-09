/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:36 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 18:46:13 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
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

#endif