/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:18:10 by rbouquet          #+#    #+#             */
/*   Updated: 2024/05/29 12:47:25 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	trim(char const *s1, char const c)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	int		len;
	char	*str;

	start = 0;
	i = 0;
	end = ft_strlen(s1) - 1;
	if (s1 == NULL || set == NULL)
		return (ft_strdup(""));
	while ((trim(set, s1[start]) == 1))
		start++;
	while ((trim(set, s1[end]) == 1 && end > start))
		end--;
	len = (end - start);
	str = malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	while (i <= len)
		str[i++] = (char)s1[start++];
	str[i] = '\0';
	return (str);
}
