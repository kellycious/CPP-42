/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:53:06 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/05 20:28:27 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "-------------- MANDATORY MAIN-------------- " << std::endl;
	std::cout << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Last added value: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Size after one pop: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "Stack numbers: ";
	while (it != ite)
	{
		std::cout  << *it << " | ";
		++it;
	}
	std::cout << std::endl;
	
	MutantStack<int> s(mstack);
	std::cout << std::endl;
	
	std::cout << "-------------- EXTRA MAIN-------------- " << std::endl;
	std::cout << std::endl;
	std::cout << "A copy of mstack has been created" << std::endl;
	s.push(+1);
	s.push(-14);
	std::cout << "Updated size: " << s.size() << std::endl;
	std::cout << "Last added value: " << s.top() << std::endl;
	std::cout << std::endl;
	
	MutantStack<int> assignment = s;
	std::cout << "An assignment from the copy to a new Mutant Stack has been created" << std::endl;
	std::cout << "Assignment stack numbers: ";
	for (MutantStack<int>::iterator start = assignment.begin(); start != assignment.end(); start++)
		std::cout << *start << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
}