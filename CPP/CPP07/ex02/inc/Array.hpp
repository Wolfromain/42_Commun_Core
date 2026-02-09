/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:35:49 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/18 09:59:13 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
	private:

		T* _array;
		int _size;

	public:

		Array() : _array(new T[0]), _size(0) 
		{
		}

		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
		}

		Array(const Array &cpy) : _array(new T[cpy._size]), _size(cpy._size)
		{
			for (int i = 0; i < this->_size; i++)
				(this->_array)[i] = cpy._array[i];
		}

		~Array()
		{
			delete [] this->_array;
		}

		Array &operator=(const Array &f)
		{
			if (this != &f)
			{
				T* newArray = new T[f._size]();
				for (int i = 0; i < f._size; i++)
					newArray[i] = f._array[i];
				delete[] _array;
				_array = newArray;
				_size = f._size;
			}
			return (*this);
		}

		T &operator[](int index)
		{
			if (index < 0 || index >= this->_size)
				throw std::out_of_range("Index out of range");
			return (this->_array[index]);
		}

		const T &operator[](int index) const
		{
			if (index < 0 || index >= this->_size)
				throw std::out_of_range("Index out of range");
			return (this->_array[index]);
		}

		int	size(void) const
		{
			return (this->_size);
		}

		void setSize(size_t size)
		{
			this->_size = size;
		}

		void printArray(void) const
		{
			for (int i = 0; i < this->_size; i++)
				std::cout << this->_array[i] << " ";
			std::cout << std::endl;
		}

};

#endif