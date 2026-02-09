/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:50:45 by rbouquet          #+#    #+#             */
/*   Updated: 2024/05/29 11:56:07 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		++len;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;
	long	nbr;

	len = int_len(n);
	i = 0;
	nbr = n;
	str = malloc(sizeof(char ) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		i = 1;
	}
	while (len > i)
	{
		str[len - 1] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
