/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:54:37 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/19 17:04:07 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {};

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[32mRobotomyRequestForm for " << this->_target << " created\033[0m" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : AForm(cpy), _target(cpy._target)
{
	std::cout << "\033[32mRobotomyRequestForm for " << this->_target << " created by copy\033[0m" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[31mRobotomyRequestForm for " << this->_target << " destroyed\033[0m" << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy)
{
	AForm::operator=(cpy);
	return *this;
};

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::srand(std::time(NULL));
	
	int r = std::rand();
	if (r % 2 == 0)
		std::cout << "\033[32m" << this->_target << " has been robotomized successfully\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << this->_target << " robotomization failed\033[0m" << std::endl;
}
