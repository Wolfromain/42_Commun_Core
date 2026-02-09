/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:47:03 by rbouquet          #+#    #+#             */
/*   Updated: 2024/06/15 09:47:23 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hexa(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_print_hexa_upper(unsigned int n)
{
	if (n >= 16)
	{
		ft_print_hexa_upper(n / 16);
		ft_print_hexa_upper(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar(n + 55);
		else
			ft_putchar(n + 48);
	}
	return (ft_len_hexa(n));
}

int	ft_print_hexa_lower(unsigned int n)
{
	if (n >= 16)
	{
		ft_print_hexa_lower(n / 16);
		ft_print_hexa_lower(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar(n + 87);
		else
			ft_putchar(n + 48);
	}
	return (ft_len_hexa(n));
}
