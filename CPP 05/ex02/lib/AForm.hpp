/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:52:22 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 17:31:35 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <exception>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &cpy);
		virtual ~AForm();

		AForm& operator=(AForm const &cpy);

		std::string const &getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		virtual void beSigned(Bureaucrat const &b);
		virtual bool requirementscheck(Bureaucrat const &b) const;
		virtual void execute(Bureaucrat const &executor) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("\e[0;31mForm's Grade is too high\033[0m"); }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("\e[0;31mForm's Grade is too low\033[0m"); }
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("\e[0;31mForm is not signed\033[0m"); }
		};

		class AllowedToExecuteException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("\e[0;31mBureaucrat is not allowed to execute - grade too low\033[0m"); }
		};
		
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream& operator<<(std::ostream &o, AForm const &f);

#endif