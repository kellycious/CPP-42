/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:10:03 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 14:12:57 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static int strint(std::string &str)
{
	std::istringstream stream(str);
	int result = 0;
	if (!(stream >> result))
		throw std::invalid_argument("Invalid argument");
	return result;
}

int main()
{
	std::cout << "\033[35mInsert Bureaucrat name:\033[0m" << std::endl;
	std::string name;
	std::getline(std::cin, name);
	std::cout << "\033[35mInsert Bureaucrat grade:\033[0m" << std::endl;
	std::string grade;
	std::getline(std::cin, grade);
	std::cout << std::endl;

	try
	{
		std::cout << "-------------------------------" << std::endl;
		Bureaucrat b(name, strint(grade));
		std::cout << std::endl;
		std::cout << "\033[35mIncrementing grade:\033[0m" << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		std::cout << "\033[35mDecrementing grade:\033[0m" << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
	
}