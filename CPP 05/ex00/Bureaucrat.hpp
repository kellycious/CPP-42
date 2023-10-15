/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:10:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/15 14:01:35 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &cpy);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat const &cpy);

		std::string const &getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("\e[0;31mGrade is too high\033[0m"); }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ return ("\e[0;31mGrade is too low\033[0m"); }
		};

		void incrementGrade();
		void decrementGrade();
		
	
	protected:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &o, Bureaucrat const &b);

#endif