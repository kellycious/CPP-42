/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:24:48 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 15:43:19 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {};

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << "\e[0;32mCreating Form " << this->_name << " \e[0;32m | grade to sign: \033[0m" << this->_gradeToSign << " \e[0;32m- grade to execute: \033[0m" << this->_gradeToExecute << std::endl;
};

Form::Form(Form const &cpy) : _name(cpy._name), _signed(cpy._signed), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
	std::cout << "\e[0;32mCreating Form " << this->_name << " by copy | grade to sign: \033[0m" << this->_gradeToSign << "\e[0;32m - grade to execute: \033[0m" << this->_gradeToExecute  << std::endl;
};

Form::~Form()
{
	std::cout << "\e[0;31mForm " << this->_name << " : destroyed\033[0m" << std::endl;
};

Form& Form::operator=(Form const &cpy)
{
	if (this != &cpy)
		this->_signed = cpy._signed;
	return *this;
};

std::string const &Form::getName() const { return this->_name;};

bool Form::getSigned() const { return this->_signed; };

int Form::getGradeToSign() const { return this->_gradeToSign; };

int Form::getGradeToExecute() const { return this->_gradeToExecute; };

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
};

std::ostream& operator<<(std::ostream &o, Form const &f)
{
	o << "Form " << f.getName() << " signed by " << f.getSigned() << " - grade to sign: " << f.getGradeToSign() << " - grade to execute: " << f.getGradeToExecute();
	return o;
};