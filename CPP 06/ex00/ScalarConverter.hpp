/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:07:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/19 18:18:59 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(std::string const &s);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &rhs);

		static int convert(std::string const &s);

	private:
		std::string _s;
};

#endif