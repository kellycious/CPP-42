/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:10:14 by khuynh            #+#    #+#             */
/*   Updated: 2023/09/29 16:25:53 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

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

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
	protected:
		std::string const _name;
		int _grade;
}