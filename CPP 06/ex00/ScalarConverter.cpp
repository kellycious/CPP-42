/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:07:23 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/22 19:19:16 by khuynh           ###   ########.fr       */
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

static void Cerror()
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: Impossible" << std::endl;
	std::cout << "double: Impossible" << std::endl;
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
	if (nb < 0 || nb > 127)
		std::cout << "impossible" << std::endl;
	else if (nb < 32 || nb == 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
}

static void Cfloat(std::string literal)
{
	float nb = atof(literal.c_str());
	std::cout << "char: ";
	if (nb < 0 || nb > 127)
		std::cout << "Impossible" << std::endl;
	else if (nb < 32 || nb == 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
}

static void Cdouble(std::string literal)
{
	double nb = atof(literal.c_str());
	std::cout << "char: ";
	if (nb < 0 || nb > 127)
		std::cout << "Impossible" << std::endl;
	else if (nb < 32 || nb == 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << literal[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << nb << std::endl;
}

static void CInf(std::string literal)
{
	double nb = atof(literal.c_str());
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << nb << std::endl;
}

static void CNan()
{
	std::cout << "char: Impossible " << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float : nanf" << std::endl;
	std::cout << "double: nan" << std::endl; 
}

void	ScalarConverter::convert(std::string const &literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		Cchar(literal);
	else if (std::isfinite(atof(literal.c_str())) || atof(literal.c_str()) < __FLT_MIN__ || atof(literal.c_str()) > __FLT_MAX__)
		Cerror();
	else if (literal == "nan" || literal == "nanf")
		CNan();
	else if (literal == "+inff" || literal == "+inf" || literal == "inf" || literal == "inff" || literal == "-inf" ||
		literal == "-inff")
		CInf(literal);
	else if (literal[literal.length() - 1] == 'f')
	{
		long unsigned int i = 0;
		while ((i < literal.length() - 1 && std::isdigit(literal[i])) || literal[i] == '.')
			i++;
		if (i == literal.length() - 1)
			Cfloat(literal);
		else
			Cerror();
	}
	else if (literal.find('.') != std::string::npos)
	{
		long unsigned int i = 0;
		while (std::isdigit(literal[i]) || literal[i] == '.')
			i++;
		if (i == literal.length())
			Cdouble(literal);
		else
			Cerror();
	}
	else if (((literal[0] == '+' || literal[0] == '-') && std::isdigit(literal[1])) || std::isdigit(literal[0]))
		Cint(literal);
	else
		Cerror();
}