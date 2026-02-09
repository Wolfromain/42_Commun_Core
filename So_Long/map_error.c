/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:40:50 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/07 11:07:06 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_around_map(t_data *data)
{	
	int	x;
	int	y;

	y = data->line;
	while (y--)
	{
		x = data->column;
		if ((data->map[y][0] != '1')
			|| (data->map[y][data->column - 1] != '1'))
			check_error(data, 9);
		if (y == 0 || y == data->line - 1)
		{
			while (x--)
			{
				if (data->map[0][x] != '1'
					|| data->map[data->line - 1][x] != '1')
					check_error(data, 9);
			}
		}
	}
}

void	check_map_size(t_data *data)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(data->map[0]);
	if (data->x > 1920 || data->y > 1080)
	{
		check_error(data, 13);
		free_all(data);
	}
	if (!data->column || !data->line || data->column < 3
		|| data->line < 3 || data->column == data->line)
		check_error(data, 6);
	while (x < ((data->y / 64) - 1))
	{
		if (ft_strlen(data->map[x]) != len || data->map[x][0] != '1'
		|| data->map[x][len - 2] != '1')
			check_error(data, 6);
		x++;
	}
}

void	check_elements(t_data *data)
{
	int	x;
	int	y;

	y = data->line;
	while (y--)
	{
		x = data->column;
		while (x--)
		{
			if (!ft_strchr(("PEC10"), data->map[y][x]))
				check_error(data, 10);
			else if (data->map[y][x] == 'P')
			{
				data->player_nbr++;
				data->player_x = x;
				data->player_y = y;
			}
			else if (data->map[y][x] == 'C')
				data->cons_nbr++;
			else if (data->map[y][x] == 'E')
				data->exit_nbr++;
		}
	}
	if (data->cons_nbr <= 0 || data->exit_nbr != 1 || data->player_nbr != 1)
		check_error(data, 11);
}

void	check_map_ext(t_data *data, char *map)
{
	if (!ft_strnstr(&map[ft_strlen(map) - 4], ".ber", 4))
		check_error(data, 7);
}

void	map_check(t_data *data, char *map)
{
	check_map_ext(data, map);
	load_map(data, map);
	check_map_size(data);
	wall_around_map(data);
	check_elements(data);
}
