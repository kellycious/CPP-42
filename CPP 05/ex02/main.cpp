/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:10:03 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/19 17:14:00 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/AForm.hpp"
#include "lib/Bureaucrat.hpp"
#include "lib/PresidentialPardonForm.hpp"
#include "lib/RobotomyRequestForm.hpp"
#include "lib/ShrubberyCreationForm.hpp"

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
	std::cout << "\033[35mInsert Number of Form requested:" << std::endl;
	std::cout << "1. ShrubberyCreationForm" << std::endl;
	std::cout << "2. RobotomyRequestForm" << std::endl;
	std::cout << "3. PresidentialPardonForm\033[0m" << std::endl;
	std::string formrequest;
	std::getline(std::cin, formrequest);
	if (strint(formrequest) < 1 || strint(formrequest) > 3)
	{
		std::cout << "Invalid form request" << std::endl;
		return 1;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "-------------------------------" << std::endl;
		Bureaucrat b(name, strint(grade));
		std::cout << std::endl;
		
		std::cout << "Insert target name:" << std::endl;
		std::string target;
		std::getline(std::cin, target);
		
		if (strint(formrequest) == 1)
		{
			ShrubberyCreationForm f(target);
			b.signForm(f);
			b.executeForm(f);
		}
		else if (strint(formrequest) == 2)
		{
			RobotomyRequestForm f(target);
			b.signForm(f);
			b.executeForm(f);
		}
		else if (strint(formrequest) == 3)
		{
			PresidentialPardonForm f(target);
			b.signForm(f);
			b.executeForm(f);
		}
		std::cout << "-------------------------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
	
}