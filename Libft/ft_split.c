/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:45:23 by rbouquet          #+#    #+#             */
/*   Updated: 2024/05/29 15:14:59 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	words;
	int	in;

	in = 0;
	words = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			++s;
		while (*s != '\0' && *s != c)
		{
			if (in == 0)
			{
				++words;
				in = 1;
			}
			++s;
		}
		in = 0;
	}
	return (words);
}

static char	**secure_malloc(char **value)
{
	int	i;

	i = 0;
	while (value[i])
		free(value[i++]);
	free(value);
	return (NULL);
}

static char	*cpy(char *s, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] != '\0' && sep(s[i], c) == 0)
		++i;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (j < i)
	{
		str[j] = s[j];
		++j;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	char	**value;

	i = 0;
	words = count_words(s, c);
	value = malloc(sizeof(char *) * (words + 1));
	if (value == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && sep(*s, c) == 1)
			++s;
		if (*s != '\0')
		{
			value[i] = cpy((char *)s, c);
			if (!(value[i]))
				return (secure_malloc(value));
			++i;
		}
		while (*s != '\0' && sep(*s, c) == 0)
			++s;
	}
	value[i] = NULL;
	return (value);
}
