/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:33:46 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/29 00:17:53 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(RPN const & copy)
{
	*this = copy;
};

RPN::~RPN() {};

RPN & RPN::operator=(RPN const & src)
{
	if (this != &src)
	{
		_stack = src._stack;
	}
	return *this;
}

void	RPN::Calculate(int a, int b, char op)
{
	if (op == '+')
		_stack.top() = a + b;
	else if (op == '-')
		_stack.top() = b - a;
	else if (op == '*')
		_stack.top() = a * b;
	else if (op == '/')
	{
		if (b == 0)
			throw std::invalid_argument("Division by zero");
		_stack.top() = b / a;
	}
}

void	RPN::Execute(std::string input)
{
	std::string op = "+-/*";
	size_t pos = 0;
	size_t num = 0;

	for (size_t i = 0; i < input.length() ; i++)
	{
		if (isdigit(input[i]))
		{
			num++;
			this->_stack.push(input[i] - '0');
		}
		else if (op.find(input[i]) != std::string::npos)
		{
			pos++;
			if (_stack.size() < 2)
				throw std::invalid_argument("Invalid number of operands");
			int a = _stack.top();
			_stack.pop();
			Calculate(a, _stack.top(), input[i]);
		}
		
		else if (input[i] == ' ')
			continue ;
		else
			throw std::invalid_argument("Invalid input");
	}
	if ((pos + 1) != num)
		throw std::invalid_argument("Invalid number of operators");
	std::cout << _stack.top() << std::endl;
}
