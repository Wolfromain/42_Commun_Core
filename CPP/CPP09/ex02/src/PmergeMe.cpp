/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:15:42 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/23 14:13:00 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int ft_Jacobsthal(int value)
{
	int	a = 0;
	int	b = 1;
	int res = 0;
	if (value == 0)
		return (0);
	else if (value == 1)
		return (1);
	for (int i = 2; i <= value; i++)
	{
		res = b + 2 * a;
		a = b;
		b = res;
	}
	return (res);
}
