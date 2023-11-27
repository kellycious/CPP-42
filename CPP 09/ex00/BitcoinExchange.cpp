/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:52:13 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/28 00:30:13 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy){ *this = cpy;};

BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &src)
{
	(void)src;
	return (*this);
}

void BitcoinExchange::InputRead()
{
	std::ifstream input("./data.csv");
	
	if (!input.is_open())
	{
		std::cerr << "Error: File not opening." << std::endl;
		return ;
	}
	
	std::string database;
	
// extract the date by keeping 10 digit, and erase "-"
// convert = substr to 11 to keep the rate only
// error on rate = invalid format, over/underflow 

	while (input >> database)
	{
		std::string date = database.substr(0,10).erase(4,1).erase(6,1);
		float rate = 0.0;
		std::stringstream convert(database.substr(11));
		
		if (!(convert >> rate))
		{
			std::cerr << "Error: could not retrieve rate" << date << std::endl;
			continue;
		}
		_data.insert(std::make_pair(date, rate));
	}
	
}

int BitcoinExchange::ParserDate(int year, int month, int day, std::string line)
{
	size_t delimitor = line.find("|");
	if (delimitor == std::string::npos || line[delimitor + 1] != ' ' || line[delimitor - 1] != ' ')
		return (std::cerr << "Invalid pipe" << std::endl, 1);
	
	if (line.substr(4, 1) != "-" && line.substr(7, 1) != "-")
		return (std::cerr << "Invalid date format" << std::endl, 1);

	if (year < 2009 || year > 2023)
		return (std::cerr << "Outbound year" << std::endl, 1);
		
	if (year == 2022 && month == 3)
	{
		if (month == 3 && day >= 30)
			return (std::cerr << "Outbound date" << std::endl, 1);
		if (month >= 4)
			return (std::cerr << "Outbound date" << std::endl, 1);
	}
	
	if (month < 1 || month > 12)
		return (std::cerr << "Outbound month" << std::endl, 1);

	if (day < 1 || day > 31)
		return (std::cerr << "Outbound day" << std::endl, 1);

// check 30 days month

	if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		return (std::cerr << "Outbound day" << std::endl, 1);

// check leap year

	if (day == 29 && month == 2 && year % 4 != 0)
		return (std::cerr << "Outbound day" << std::endl, 1);

	else
		return (0);
}

int BitcoinExchange::ParserRate(float rate, std::string line)
{
	int x = 0;
	for (size_t i = 0; i < line.length(); i++)
	{
		if (line[0] == '.')
			return (std::cerr << "Invalid value" << std::endl, 1);
		if (line[i] == '.')
			x++;
		if (!isdigit(line[i]) && line[i] != '.' && (x == 0 || x > 1))
			return (std::cerr << "Invalid value" << std::endl, 1);
	}
	if (rate < 0.0 || rate > 100000.0)
		return (std::cerr << "Outbound value" << std::endl, 1);
	else
		return (0);
}

void	BitcoinExchange::Printer(std::string date, float rate)
{
	std::map<std::string, float>::const_iterator it;
	float result;
	
	it = _data.find(date);
	if (it != _data.end())
		result = it->second * rate;
	else
	{
		it = _data.lower_bound(date);
		result = it->second * rate;
	}
	std::cout << date.insert(4,"-").insert(7,"-") << " => " << rate << " = " << std::fixed << std::setprecision(2) << result << std::endl;
		
}

void	BitcoinExchange::Exchanger(std::string file)
{
	std::ifstream input(file);
	std::string line;

	if (!input.is_open())
	{
		std::cerr << "Error: File not opening." << std::endl;
		input.close();
		return ;
	}

	while (std::getline(input, line))
	{
		int year = 0;
		int month = 0;
		int day = 0;
		std::stringstream yconvert;
		std::stringstream mconvert;
		std::stringstream dconvert;

		if (line.length() < 14)
		{
			std::cerr << "Invalid format" << std::endl;
			continue;
		}
		yconvert << line.substr(0, 4);
		mconvert << line.substr(5, 2);
		dconvert << line.substr(8, 2);
		yconvert >> year;
		mconvert >> month;
		dconvert >> day;

		std::string date;

		if (month < 10 && day < 10)
			date = std::to_string(year*10)  + std::to_string(month*10) + std::to_string(day);
		else if (month < 10)
			date = std::to_string(year*10) + std::to_string(month) + std::to_string(day);
		else if (day < 10)
			date = std::to_string(year) + std::to_string(month*10) + std::to_string(day);
		else
			date = std::to_string(year) + std::to_string(month) + std::to_string(day);
		
		float rate = 0.00;
		std::string line2 = line.substr(13, line.find('\0'));
		std::stringstream rconvert;
		
		rconvert << line2;
		rconvert >> rate;

		if (ParserDate(year, month, day, line) == 0 && ParserRate(rate, line2) == 0)
			Printer(date, rate);
	}
}