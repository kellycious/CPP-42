/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:10:03 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 15:44:27 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/Bureaucrat.hpp"

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
	std::cout << "\033[35mInsert Form name:\033[0m" << std::endl;
	std::string formname;
	std::getline(std::cin, formname);
	std::cout << "\033[35mInsert Form grade to sign:\033[0m" << std::endl;
	std::string gradetosign;
	std::getline(std::cin, gradetosign);
	std::cout << "\033[35mInsert Form grade to execute:\033[0m" << std::endl;
	std::string gradetoexecute;
	std::getline(std::cin, gradetoexecute);
	std::cout << std::endl;

	try
	{
		std::cout << "-------------------------------" << std::endl;
		Bureaucrat b(name, strint(grade));
		std::cout << std::endl;
		Form f(formname, strint(gradetosign), strint(gradetoexecute));
		std::cout << std::endl;
		b.signForm(f);
		std::cout << "-------------------------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
	
}