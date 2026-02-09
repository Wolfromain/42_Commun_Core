/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:25:31 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/28 12:38:48 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

const char	*valid_input(const char *str)
{
	int			len;
	const char	*nbr;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		return (printf("Only positif number is allow\n"), NULL);
	if (!is_digit(*str))
		return (printf("Only digit number is allow\n"), NULL);
	nbr = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		return (printf("Value too big, the limit is INT MAX\n"), NULL);
	return (nbr);
}

long	ft_atol(const char *str)
{
	long	nb;

	nb = 0;
	str = valid_input(str);
	if (str == NULL)
		return (-1);
	while (is_digit(*str))
		nb = (nb * 10) + (*str++ - 48);
	if (nb > INT_MAX)
		return (printf("Value too big,the limit is INT MAX\n"), -1);
	return (nb);
}
