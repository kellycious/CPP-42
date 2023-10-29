/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:23:51 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/29 23:59:52 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	public:
		// create an empty array
		Array() : _array(new T[0]), _size(0){}
		
		// create an array of n elements
		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
			for (unsigned int i = 0; i < n; i++)
				_array[i] = 0;
		}
		
		// deep copy
		Array(Array const &cp) : _array(new T[cp._size], _size(cp._size))
		{
			for (unsigned int i = 0; i < _size; i++)
				_array = cp._array[i];
		}
		
		// delete each elements
		~Array(){ delete[] _array; }

		// assignment operator
		Array<T> &operator=(Array const &cp)
		{
			if (this != &cp)
			{
				delete[] _array;
				_size = cp._size;
				_array = new T[_size];

				for (int i = 0; i < _size; i++)
					_array[i] = cp._array[i];
			}
			return (*this);
		}

		// [] operator
		T &operator[](int n)
		{
			if (n >= _size)
				throw Outofbounds();
			return (_array[n]);
		}

		class Outofbounds : public std::exception
		{
			const char *what() const throw() { return ("Index is out of bounds"); }
		};
		
		int size(){ return _size;}
		
	private:
		T	*_array;
		int	_size;
		
};

#endif 
