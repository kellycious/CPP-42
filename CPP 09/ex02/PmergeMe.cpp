/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:23:20 by khuynh            #+#    #+#             */
/*   Updated: 2023/12/04 01:09:20 by khuynh           ###   ########.fr       */
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
	if (ac < 2)
		throw std::invalid_argument("Invalid input: Numbers are required");
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

// Recursive function to sort the sequence by the largest pair value

static void recursort(std::vector<std::pair<int, int> > &vecpair, size_t start, size_t end)
{
	if (start < end)
	{
		size_t max = start;
		for (size_t i = start + 1; i < end; ++i)
		{
			if (std::max(vecpair[i].first, vecpair[i].second) < std::max(vecpair[max].first, vecpair[max].second))
				max = i;
		}
		std::swap(vecpair[max], vecpair[end - 1]);
		recursort(vecpair, start, end - 1);
	}
}

// Binary search function to find the insertion point 

static size_t binsearch(const std::vector<int>& vec, int nb, int left, int right)
{
	if (abs(left - right) <= 1)
		return (left);
	
	size_t mid = (left + right) / 2 - 1;
	
	if (nb > vec[mid])
		return (binsearch(vec, nb, mid + 1, right));
	else
		return (binsearch(vec, nb, left, mid));
}

static void	specialinsert(std::vector<int> &vec, int value, size_t index)
{
	std::vector<int>::iterator it = vec.begin() + index;
	
	if (value > vec[index])
		it = vec.begin() + index + 1;

	vec.insert(it, value);
}

void FJMI::sort_vector()
{
	// make pairs, if odd, store it
	std::vector<std::pair<int, int> > vecpair;

	size_t i = 0;
	for (; i < _size - 1; i+=2)
		vecpair.push_back(std::make_pair(_vec[i], _vec[i + 1]));
	if (i < _size)
		_odd = _vec[i];

	// sort index of each pair
	for (size_t i = 0; i < vecpair.size(); ++i)
	{
		if (vecpair[i].first > vecpair[i].second)
			std::swap(vecpair[i].first, vecpair[i].second);
	}
		
	// sort by largest pair value
	recursort(vecpair, 0, vecpair.size());

	// push highest value of each pair to the initial vector by cleaning it first
	_vec.clear();
	for (size_t i = 0; i < vecpair.size(); ++i)
		_vec.push_back(vecpair[i].first);

	// optimal = remaining numbers + odd if exist 

	std::vector<int> optimal;

	for (size_t i = 0; i < vecpair.size(); ++i)
		optimal.push_back(vecpair[i].second);
	if (_odd != 0)
		optimal.push_back(_odd);

	std::sort(_vec.begin(), _vec.end());

	// insert optimal values to original vector by binary insertion

	while (!optimal.empty())
	{
		size_t InsertionIndex = binsearch(_vec, *(optimal.begin()), 0, _vec.size());
		specialinsert(_vec, *(optimal.begin()), InsertionIndex);
		optimal.erase(optimal.begin());
	}

}

void FJMI::fordjohnson_vector()
{
	clock_t start = clock();
	sort_vector();
	clock_t end = clock();
	_vectime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Vector time: " << _vectime << "ms" << std::endl;
}
/*
void FJMI::fordjohnson_deque()
{
	clock_t start = clock();
	sort_deque();
	clock_t end = clock();
	_deqtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Deque time: " << _deqtime << "ms" << std::endl;
}*/

