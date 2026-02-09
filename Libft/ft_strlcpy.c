/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:00:40 by rbouquet          #+#    #+#             */
/*   Updated: 2024/05/23 16:04:05 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while ((i < (n - 1)) && src[i] != '\0')
		{
			dest[i] = (char)src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen((char *)src));
}
