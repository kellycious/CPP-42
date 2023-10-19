/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:54:35 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/19 16:32:18 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default"){};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\033[32mShrubberyCreationForm for " << this->_target << " created\033[0m" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : AForm(cpy), _target(cpy._target)
{
	std::cout << "\033[32mShrubberyCreationForm for " << this->_target << " created by copy\033[0m" << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[31mShrubberyCreationForm for " << this->_target << " destroyed\033[0m" << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy) 
{
	AForm::operator=(cpy);
	return *this;
};

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::ofstream ofs;
	std::string filename = this->_target + "_shrubbery";
	ofs.open(filename.c_str());
	if (ofs.is_open())
	{
		for (int i = 0; i < 4; ++i) 
		{
			ofs << "     ^ ^ ^" << std::endl;
			ofs << "    ^ ^ ^ ^" << std::endl;
			ofs << "   ^ ^ ^ ^ ^" << std::endl;
			ofs << "  ^ ^ ^ ^ ^ ^" << std::endl;
			ofs << " ^ ^ ^ ^ ^ ^ ^" << std::endl;
			ofs << "^ ^ ^ ^ ^ ^ ^ ^" << std::endl;
			ofs << "      |||" << std::endl << std::endl;
		}
		ofs.close();
	}
	else
		std::cout << "Error opening file" << std::endl;
};
