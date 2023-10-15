/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:54:40 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 17:31:46 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {};

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[32mPresidentialPardonForm for " << this->_target << " created\033[0m" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy) : AForm(cpy), _target(cpy._target)
{
	std::cout << "\033[32mPresidentialPardonForm for " << this->_target << " created by copy\033[0m" << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[31mPresidentialPardonForm for " << this->_target << " destroyed\033[0m" << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy)
{
	AForm::operator=(cpy);
	return *this;
};

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << "\033[32m" << this->_target << " has been pardoned by Zaphod Beeblebrox\033[0m" << std::endl;
}


