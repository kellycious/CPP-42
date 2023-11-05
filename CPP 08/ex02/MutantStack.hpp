/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:53:16 by khuynh            #+#    #+#             */
/*   Updated: 2023/11/05 20:22:47 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		MutantStack(MutantStack const &cpy) : MutantStack::stack(cpy) {};
		virtual ~MutantStack(){};
		
		MutantStack &operator=(MutantStack const &src)
		{
			if (this != &src)
        		std::stack<T>::operator=(src);
			return (*this);
		}
		
		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin(){ return (this->c.begin());}
		iterator	end(){ return (this->c.end());}
};

#endif