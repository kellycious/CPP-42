/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:23:20 by khuynh            #+#    #+#             */
/*   Updated: 2023/12/04 15:03:44 by khuynh           ###   ########.fr       */
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

static void recursort_d(std::deque<std::pair<int,int> > &deqpair, size_t start, size_t end)
{
	if (start < end)
	{
		size_t max = start;
		for (size_t i = start + 1; i < end; ++i)
		{
			if (std::max(deqpair[i].first, deqpair[i].second) < std::max(deqpair[max].first, deqpair[max].second))
				max = i;
		}
		std::swap(deqpair[max], deqpair[end - 1]);
		recursort_d(deqpair, start, end - 1);
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

static size_t binsearch_d(const std::deque<int> & deq, int nb, int left, int right)
{
	if (abs(left - right) <= 1)
		return (left);
	
	size_t mid = (left + right) / 2 - 1;
	
	if (nb > deq[mid])
		return (binsearch_d(deq, nb, mid + 1, right));
	else
		return (binsearch_d(deq, nb, left, mid));
}

static void	specialinsert(std::vector<int> &vec, int value, size_t index)
{
	std::vector<int>::iterator it = vec.begin() + index;
	
	if (value > vec[index])
		it = vec.begin() + index + 1;

	vec.insert(it, value);
}

static void specialinsert_d(std::deque<int> &deq, int value, size_t index)
{
	std::deque<int>::iterator it = deq.begin() + index;
	
	if (value > deq[index])
		it = deq.begin() + index + 1;

	deq.insert(it, value);
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
	if (_size % 2 != 0)
		optimal.push_back(_odd);

	std::sort(_vec.begin(), _vec.end());

	size_t optisize = optimal.size();
	// insert optimal values to original vector by binary insertion

	for (size_t i = 0; i < optisize; ++i)
	{
		size_t InsertionIndex = binsearch(_vec, *(optimal.begin()), 0, _vec.size());
		specialinsert(_vec, *(optimal.begin()), InsertionIndex);
		optimal.erase(optimal.begin());
		if (*(optimal.begin()) == _odd)
			break;
	}
	if (_size % 2 != 0)
	{
		size_t InsertionIndex = binsearch(_vec, _odd, 0, _vec.size());
		specialinsert(_vec, _odd, InsertionIndex);
	}
}

void FJMI::sort_deque()
{
	// make pairs, if odd, store it
	std::deque<std::pair<int, int> > deqpair;

	size_t i = 0;
	for (; i < _size - 1; i+=2)
		deqpair.push_back(std::make_pair(_deq[i], _deq[i + 1]));
	if (i < _size)
		_odd = _deq[i];

	// sort index of each pair
	for (size_t i = 0; i < deqpair.size(); ++i)
	{
		if (deqpair[i].first > deqpair[i].second)
			std::swap(deqpair[i].first, deqpair[i].second);
	}
		
	// sort by largest pair value
	recursort_d(deqpair, 0, deqpair.size());

	// push highest value of each pair to the initial vector by cleaning it first
	_deq.clear();
	for (size_t i = 0; i < deqpair.size(); ++i)
		_deq.push_back(deqpair[i].first);

	// optimal = remaining numbers + odd if exist 

	std::deque<int> optimal;

	for (size_t i = 0; i < deqpair.size(); ++i)
		optimal.push_back(deqpair[i].second);
	if (_size % 2 != 0)
		optimal.push_back(_odd);

	std::sort(_deq.begin(), _deq.end());

	// insert optimal values to original vector by binary insertion
	size_t optisize = optimal.size();
	for (size_t i = 0; i < optisize; ++i)
	{
		size_t InsertionIndex = binsearch_d(_deq, *(optimal.begin()), 0, _deq.size());
		specialinsert_d(_deq, *(optimal.begin()), InsertionIndex);
		optimal.erase(optimal.begin());
		if (*(optimal.begin()) == _odd)
			break;
	}			
	if (_size % 2 != 0)
	{
		size_t InsertionIndex = binsearch_d(_deq, _odd, 0, _deq.size());
		specialinsert_d(_deq, _odd, InsertionIndex);
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

void FJMI::fordjohnson_deque()
{
	clock_t start = clock();
	sort_deque();
	clock_t end = clock();
	_deqtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Deque time: " << _deqtime << "ms" << std::endl;
}

