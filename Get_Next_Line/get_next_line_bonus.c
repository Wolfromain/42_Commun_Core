/* ************************************************************************** */
/*                                                                            */
/*                                                       ::     :::::::   */
/*   get_next_line_bonus.c                             +:     +:   +:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:38:17 by rbouquet          #+#    #+#             */
/*   Updated: 2024/06/17 12:09:37 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*str [1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = assembly(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = print_line(str[fd]);
	str[fd] = free_line(str[fd]);
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

/* #include <stdio.h>

int	main(void)
{
	int	fd;
	int	fd1;
	int	fd2;
	int	fd3;
	char	*line;
	int		nbline = 0;

	// First line of the folders
    fd = open("text.txt", O_RDONLY);
	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);

 	line = get_next_line(fd);
    printf("%s", line);
	free(line);
	line = get_next_line(fd1);
    printf("%s", line);
	free(line);
	line = get_next_line(fd2);
    printf("%s", line);
	free(line);
	line = get_next_line(fd3);
    printf("%s", line);
	free(line);


	nbline++;
	// Second line of the folders
	line = get_next_line(fd);
    printf("%s", line);
	free(line);
	line = get_next_line(fd1);
    printf("%s", line);
	free(line);
	line = get_next_line(fd2);
    printf("%s", line);
	free(line);
	line = get_next_line(fd3);
    printf("%s", line);
	free(line);

    close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
    return (0);
} */