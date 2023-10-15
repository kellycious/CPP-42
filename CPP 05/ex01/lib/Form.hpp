/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:24:27 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 15:46:32 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &cpy);
		~Form();

		Form& operator=(Form const &cpy);

		std::string const &getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &b);
		
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
		
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream& operator<<(std::ostream &o, Form const &f);

#endif