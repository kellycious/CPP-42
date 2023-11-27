/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:52:17 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/27 23:47:25 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange (BitcoinExchange const &cpy);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &src);

		void	InputRead();
		int		ParserDate(int year, int month, int day, std::string line);
		int		ParserRate(float rate, std::string line);
		void	Printer(std::string date, float rate);
		void	Exchanger(std::string file);
		
	private:
		std::map<std::string, float> _data; 
};

#endif