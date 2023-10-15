/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:54:43 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 17:08:38 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {};

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
		std::cout << "\e[0;32mCreating Form " << this->_name << " \e[0;32m | grade to sign: \033[0m" << this->_gradeToSign << " \e[0;32m- grade to execute: \033[0m" << this->_gradeToExecute << std::endl;
};

AForm::AForm(AForm const &cpy) : _name(cpy._name), _signed(cpy._signed), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
	std::cout << "\e[0;32mCreating Form " << this->_name << " by copy | grade to sign: \033[0m" << this->_gradeToSign << "\e[0;32m - grade to execute: \033[0m" << this->_gradeToExecute  << std::endl;
};

AForm::~AForm()
{
	std::cout << "\e[0;31mForm " << this->_name << " : destroyed\033[0m" << std::endl;
};

AForm& AForm::operator=(AForm const &cpy)
{
	if (this != &cpy)
		this->_signed = cpy._signed;
	return *this;
};

std::string const &AForm::getName() const { return this->_name;};

bool AForm::getSigned() const { return this->_signed; };

int AForm::getGradeToSign() const { return this->_gradeToSign; };

int AForm::getGradeToExecute() const { return this->_gradeToExecute; };

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
};

bool AForm::requirementscheck(Bureaucrat const &b) const
{
	if (b.getGrade() > this->_gradeToExecute)
		throw AForm::AllowedToExecuteException();
	else if (!this->_signed)
		throw AForm::FormNotSignedException();
	else
		return true;
};

std::ostream& operator<<(std::ostream &o, AForm const &f)
{
	o << "Form " << f.getName() << " signed by " << f.getSigned() << " - grade to sign: " << f.getGradeToSign() << " - grade to execute: " << f.getGradeToExecute();
	return o;
};