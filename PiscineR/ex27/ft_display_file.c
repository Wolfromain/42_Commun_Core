/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:41:34 by rbouquet          #+#    #+#             */
/*   Updated: 2024/05/19 13:43:43 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buf;

	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr("File name missing.\n");
		else
			ft_putstr("Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], 0);
	if (fd != -1)
	{
		while (read(fd, &buf, 1) == 1)
			write(1, &buf, 1);
		close (fd);
		return (0);
	}
	ft_putstr("Cannot read file.\n");
}
