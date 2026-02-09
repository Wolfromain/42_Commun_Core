/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:38:27 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/11 10:38:06 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T* a, size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; ++i)
		func(a[i]);
}

template <typename T>
void iter(const T* a, size_t length, void (*func)(const T&))
{
	for (size_t i = 0; i < length; ++i)
		func(a[i]);
}

template <typename T>
void printArray(T &elem)
{
	std::cout << " " << elem;
}

#endif