/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:17:57 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 19:59:15 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Intern.hpp"
#include "../lib/RobotomyRequestForm.hpp"
#include "../lib/PresidentialPardonForm.hpp"
#include "../lib/ShrubberyCreationForm.hpp"


Intern::Intern() { std::cout << "Intern created" << std::endl;}

Intern::Intern(Intern const &cpy)
{
	*this = cpy;
	std::cout << "Intern created by copy" << std::endl;
}

Intern::~Intern() { std::cout << "Intern destroyed" << std::endl;}

Intern& Intern::operator=(Intern const &cpy)
{
	(void)cpy;
	return *this;
}

AForm *	Intern::makeForm(std::string const & formName, std::string const & target)
{
	AForm *form = NULL;
	std::string const formNames[3] = {
	"robotomy request",
	"presidential pardon",
	"shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i].compare(formName) == 0)
		{
			std::cout << "Intern creates " << formName << std::endl;
			switch (i)
			{
				case 0:
					form = new RobotomyRequestForm(target);
					break;
				case 1:
					form = new PresidentialPardonForm(target);
					break;
				case 2:
					form = new ShrubberyCreationForm(target);
					break;
				default:
					std::cout << "Invalid form name" << std::endl;
			}
		}
	}
	return form;
}


