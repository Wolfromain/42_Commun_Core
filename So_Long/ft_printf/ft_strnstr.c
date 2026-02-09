/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:32:38 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/02 11:11:06 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	a;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		a = 0;
		while (big[i + a] == little[a] && little[a] != '\0' && (i + a < len))
		{
			if (little[a + 1] == '\0')
				return ((char *)&big[i]);
			a++;
		}
		i++;
	}
	return (0);
}
