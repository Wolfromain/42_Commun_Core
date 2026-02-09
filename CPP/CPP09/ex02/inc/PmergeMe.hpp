/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:15:20 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/25 14:01:06 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <limits.h>
# include <cstdlib>
# include <algorithm>
# include <ctime>
	

template <typename T>
class PmergeMe
{
	public:
	
		PmergeMe();
		PmergeMe(const PmergeMe<T> &cpy);
		PmergeMe<T> &operator=(const PmergeMe<T> &f);
		~PmergeMe();

		void	add(int value);
		void	algo(T &container);
		T& getContainer() { return _container; }
		size_t size() const { return _container.size(); }


	private:

		T	_container;
};

int ft_Jacobsthal(int value);

template <typename T>
PmergeMe<T>::PmergeMe()
{
	// std::cout << "Default constructor called" << std::endl;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &cpy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
	{
	}
	return (*this);
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
	// std::cout << "Destructor called" << std::endl;
}

template <typename T>
void PmergeMe<T>::add(int value)
{
	_container.push_back(value);
}

template <typename T>
void algo(T &container)
{
	T main;
	T pend;
	
	if (container.size() <= 1)
		return ;

	int n = container.size();
	
	for (int i = 0; i + 1 < n; i += 2) {
		if (container[i] > container[i + 1])
		{
			main.push_back(container[i]);
			pend.push_back(container[i + 1]);
		}
		else
		{
			main.push_back(container[i + 1]);
			pend.push_back(container[i]);
		}
	}
	if (container.size() % 2 != 0)
		main.push_back(container.back());
	algo(main);
	std::vector<int> IndexJacob;
	int j = 1;

	while (true)
	{
		int index = ft_Jacobsthal(j);
		if (index >= static_cast<int>(pend.size()))
			break;
		IndexJacob.push_back(index);
		++j;
	}

	for (size_t i = 0; i < pend.size(); ++i)
		if (std::find(IndexJacob.begin(), IndexJacob.end(), i) == IndexJacob.end())
			IndexJacob.push_back(i);

	for (size_t idx = 0; idx < IndexJacob.size(); ++idx)
	{
		if (std::find(main.begin(), main.end(), pend[IndexJacob[idx]]) == main.end())
		{
			typename T::iterator pos = std::lower_bound(main.begin(), main.end(), pend[IndexJacob[idx]]);
			main.insert(pos, pend[IndexJacob[idx]]);
		}
	}
	container = main;
}

#endif
