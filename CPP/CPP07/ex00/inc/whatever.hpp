/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:24:08 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/11 10:59:26 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >
void swap (T &x, T &y)
{
	T tmp;
	tmp = y;
	y = x;
	x = tmp;
}

template< typename T >
const T min (const T& x, const T& y)
{
	return (x<y ? x : y);
}

template< typename T >
const T max (const T& x, const T& y)
{
	return (x>y ? x : y);
}

#endif