/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:07:23 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/22 16:39:05 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }
ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &cpy)
{
	(void)cpy;
	return *this;
}

static void Cchar(std::string literal)
{
	std::cout << "char: '" << literal[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << std::endl;
}

static void Cint(std::string literal)
{
	int nb = atoi(literal.c_str());
	std::cout << "char: ";
	if (nb < 32 || nb == 126)
		std::cout << "Non displayable" << std::endl;
	else if (nb < 0 || nb > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << literal[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << nb << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(nb) << std::endl;
}

static void Cfloat(std::string literal)
{
	float nb = atof(literal.c_str());
	std::cout << "char: ";
	if (nb < 32 || nb == 126)
		std::cout << "Non displayable" << std::endl;
	else if (nb < 0 || nb > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << literal[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << nb << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(nb) << std::endl;
}

static void Dconvert(std::string literal)
{
	double nb = atof(literal.c_str());
	std::cout << "char: ";
	if (nb < 32 || nb == 126)
		std::cout << "Non displayable" << std::endl;
	else if (nb < 0 || nb > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << literal[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << nb << std::endl;
}

static void MIconvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}

static void MXconvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}

static void Econvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}

void	ScalarConverter::convert(std::string const &literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		Cchar(literal);
	else if (literal == "nan" || literal == "nanf")
		Econvert();
	else if (literal == "-inff" ||literal == "-inf")
		MIconvert();
	else if (literal == "+inff" || literal == "+inf" || literal == "inf" || literal == "inff")
		MXconvert();
	else if (literal[literal.length() - 1] == 'f')
	{
		long unsigned int i = 0;
		while ((i < literal.length() - 1 && std::isdigit(literal[i])) || literal[i] == '.')
			i++;
		if (i == literal.length() - 1)
			Cfloat(literal);
		else
			Econvert();
	}
	else if (literal.find('.') != std::string::npos)
	{
		long unsigned int i = 0;
		while (std::isdigit(literal[i]) || literal[i] == '.')
			i++;
		if (i == literal.length())
			Dconvert(literal);
		else
			Econvert();
	}
	else if (std::isdigit(literal[0]))
		Cint(literal);
	else
		Econvert();
}