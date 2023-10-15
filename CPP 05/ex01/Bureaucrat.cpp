/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:10:38 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 15:44:08 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {};

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		this->_grade = grade;
		std::cout << "\e[0;32mCreating Bureaucrat " << this->_name << " | grade: \033[0m" << this->_grade << std::endl;
	}
};

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) : _name(cpy._name), _grade(cpy._grade)
{
	std::cout << "\e[0;32mBureaucrat " << this->_name << " : created by copy | grade: " << this->_grade << " )\033[0m" << std::endl;
};

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mBureaucrat " << this->_name << " : destroyed\033[0m" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &cpy)
{
	if (this != &cpy)
		this->_grade = cpy._grade;
	return *this;
};

std::string const &Bureaucrat::getName() const
{
	return this->_name;
};

int Bureaucrat::getGrade() const
{
	return this->_grade;
};

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
};

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
};

void Bureaucrat::signForm( Form &f ) const
{
	try
	{
		f.beSigned(*this);
		std::cout  << this->_name << " signed " << f.getName() << " form." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\e[0;31m" << this->_name << " cannot sign " << f.getName() << " because " << e.what() << "\033[0m" << std::endl;
	}
};

std::ostream& operator<<(std::ostream &o, Bureaucrat const &b)
{
	o << "Bureaucrat " << b.getName() << " | grade: " << b.getGrade() << std::endl;
	return o;
};