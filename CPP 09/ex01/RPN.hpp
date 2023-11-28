/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:33:56 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/28 23:41:34 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	public:
		RPN();
		RPN(RPN const & copy);
		~RPN();

		RPN & operator=(RPN const & src);
		
		void	Execute(std::string input);
		void	Calculate(int a, int b, char op);
	
	private:
		std::stack<int>		_stack;
	
};

#endif 