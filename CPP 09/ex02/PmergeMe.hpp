/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:23:30 by khuynh            #+#    #+#             */
/*   Updated: 2023/12/01 02:17:54 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <deque>
# include <vector>
# include <ctime>

class FJMI
{
	public:
		FJMI();
		FJMI(FJMI const &src);
		~FJMI();

		FJMI &operator=(FJMI const &rhs);

		void input_parse(int ac, char **av);
		void print_vector();
		void print_deque();
		void sort_vector();
		void sort_deque();
		void fordjohnson_vector();
		void fordjohnson_deque();

	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		size_t 			_size;
		double 			_vectime;
		double 			_deqtime;
};

#endif