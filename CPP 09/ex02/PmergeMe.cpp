/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:23:20 by khuynh            #+#    #+#             */
/*   Updated: 2023/12/01 02:19:57 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

FJMI::FJMI() : _vectime(0), _deqtime(0){}

FJMI::FJMI(FJMI const &src) {*this = src;}

FJMI::~FJMI() {}

FJMI &FJMI::operator=(FJMI const &rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
		this->_vectime = rhs._vectime;
		this->_deqtime = rhs._deqtime;
	}
	return *this;
}

struct IsNotDigit
{
	bool operator()(char c) { return !isdigit(c); }
};

static int strtoint(std::string const &str)
{
	std::istringstream iss(str);
	int num;
	iss >> num;
	return num;
}

void FJMI::input_parse(int ac, char **av)
{
	if (ac < 3)
		throw std::invalid_argument("Invalid input: At least 2 nb is required");
	for (int i = 1; i < ac; ++i)
	{
		std::string inputnb(av[i]);
		if (av[i][0] == '-' || std::find_if(inputnb.begin(), inputnb.end(), IsNotDigit()) != inputnb.end())
			throw std::invalid_argument("Invalid input: Only positive nb are allowed");
		int num = strtoint(inputnb);
		_vec.push_back(num);
		_deq.push_back(num);
	}
	_size = _vec.size();
}

void FJMI::print_vector()
{
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

}	
void FJMI::print_deque()
{
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void FJMI::sort_vector()
{
	std::vector<int> tmp;
	std::vector<int> tmp2;
	std::vector<int> final;

	std::vector<int>::iterator it = _vec.begin();
	if (_size % 2 == 0)
	{
		for (size_t i = 0; i < _size / 2; ++i)
		{
			tmp.push_back(*it);
			++it;
		}
		for (size_t i = _size / 2; i < _size; ++i)
		{
			tmp2.push_back(*it);
			++it;
		}
	}
	else
	{
		for (size_t i = 0; i < _size / 2 + 1; ++i)
		{
			tmp.push_back(*it);
			++it;
		}
		for (size_t i = _size / 2 + 1; i < _size; ++i)
		{
			tmp2.push_back(*it);
			++it;
		}
	}
	std::sort(tmp.begin(), tmp.end());
	std::sort(tmp2.begin(), tmp2.end());
	while (!tmp.empty() && !tmp2.empty())
	{
		if (tmp.front() < tmp2.front())
		{
			final.push_back(tmp.front());
			tmp.erase(tmp.begin());
		}
		else
		{
			final.push_back(tmp2.front());
			tmp2.erase(tmp2.begin());
		}
	}
	if (!tmp.empty() && tmp2.empty())
	{
		while (!tmp.empty())
		{
			final.push_back(tmp.front());
			tmp.erase(tmp.begin());
		}
	}
	else if (tmp.empty() && !tmp2.empty())
	{
		while (!tmp2.empty())
		{
			final.push_back(tmp2.front());
			tmp2.erase(tmp2.begin());
		}
	}
	_vec = final;
}

void FJMI::sort_deque()
{
	std::deque<int> tmp;
	std::deque<int> tmp2;
	std::deque<int> final;

	std::deque<int>::iterator it = _deq.begin();
	if (_size % 2 == 0)
	{
		for (size_t i = 0; i < _size / 2; ++i)
		{
			tmp.push_back(*it);
			++it;
		}
		for (size_t i = _size / 2; i < _size; ++i)
		{
			tmp2.push_back(*it);
			++it;
		}
	}
	else
	{
		for (size_t i = 0; i < _size / 2 + 1; ++i)
		{
			tmp.push_back(*it);
			++it;
		}
		for (size_t i = _size / 2 + 1; i < _size; ++i)
		{
			tmp2.push_back(*it);
			++it;
		}
	}
	std::sort(tmp.begin(), tmp.end());
	std::sort(tmp2.begin(), tmp2.end());
	while (!tmp.empty() && !tmp2.empty())
	{
		if (tmp.front() < tmp2.front())
		{
			final.push_back(tmp.front());
			tmp.erase(tmp.begin());
		}
		else
		{
			final.push_back(tmp2.front());
			tmp2.erase(tmp2.begin());
		}
	}
	if (!tmp.empty() && tmp2.empty())
	{
		while (!tmp.empty())
		{
			final.push_back(tmp.front());
			tmp.erase(tmp.begin());
		}
	}
	else if (tmp.empty() && !tmp2.empty())
	{
		while (!tmp2.empty())
		{
			final.push_back(tmp2.front());
			tmp2.erase(tmp2.begin());
		}
	}
	_deq = final;
}

void FJMI::fordjohnson_vector()
{
	clock_t start = clock();
	sort_vector();
	clock_t end = clock();
	_vectime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Vector time: " << _vectime << std::endl;
}

void FJMI::fordjohnson_deque()
{
	clock_t start = clock();
	sort_deque();
	clock_t end = clock();
	_deqtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Deque time: " << _deqtime << std::endl;
}

