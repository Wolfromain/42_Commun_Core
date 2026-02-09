/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:10:09 by rbouquet          #+#    #+#             */
/*   Updated: 2024/06/17 12:16:01 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = assembly(fd, str);
	if (!str)
		return (NULL);
	line = print_line(str);
	str = free_line(str);
	return (line);
}

char	*assembly(int fd, char *str)
{
	char	*buffer;
	int		readed;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[readed] = '\0';
		if (str != NULL)
			str = ft_strjoin(str, buffer);
		else
			str = ft_strdup(buffer);
	}
	free(buffer);
	return (str);
}

char	*print_line(char *str)
{
	unsigned int	len_print;
	unsigned int	i;
	char			*next_line;

	len_print = 0;
	i = 0;
	if (!(*str))
		return (NULL);
	while (str[len_print] != '\n' && str[len_print])
		len_print++;
	if (str[len_print] == '\n')
		len_print++;
	next_line = malloc(sizeof(char) * (len_print + 1));
	if (!next_line)
		return (NULL);
	while (i < len_print)
	{
		next_line[i] = str[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*free_line(char *str)
{
	unsigned int		len_free;
	unsigned int		i;
	char				*temp;

	i = 0;
	len_free = 0;
	while (str[len_free] != '\n' && str[len_free])
		len_free++;
	if (!str[len_free])
	{
		free (str);
		return (NULL);
	}
	len_free++;
	temp = malloc(sizeof(char) * (ft_strlen(str) - len_free + 1));
	if (!temp)
		return (NULL);
	while (str[len_free])
		temp[i++] = str[len_free++];
	temp[i] = '\0';
	free(str);
	return (temp);
}
/* # include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.h", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
