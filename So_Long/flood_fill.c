/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:12:02 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/05 09:45:58 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(t_data *data, char **map)
{
	char	**tmp_map;
	int		i;

	tmp_map = malloc((data->line + 1) * sizeof(char *));
	if (!tmp_map)
		check_error(data, 1);
	i = -1;
	while (++i < data->line)
	{
		tmp_map[i] = ft_strdup(map[i]);
		if (!tmp_map)
		{
			free_array(tmp_map);
			check_error(data, 1);
		}
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

void	fill(t_data *data, char **map, int y, int x)
{
	if (y < 0 || y > data->line || x < 0 || x > data->column
		|| (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'P'))
		return ;
	map[y][x] = 'x';
	fill(data, map, (y + 1), x);
	fill(data, map, (y - 1), x);
	fill(data, map, y, (x + 1));
	fill(data, map, y, (x - 1));
}

bool	check_fill(t_data *data, char **tmp_map)
{
	int	x;
	int	y;

	y = data->line;
	while (y--)
	{
		x = data->column;
		while (x--)
		{
			if (tmp_map[y][x] == 'C')
				return (false);
			if (tmp_map[y][x] == 'E' && (tmp_map[y + 1][x] != 'x'
				&& tmp_map[y - 1][x] != 'x' && tmp_map[y][x + 1] != 'x'
				&& tmp_map[y][x - 1] != 'x'))
				return (false);
		}
	}
	return (true);
}

void	flood_fill(t_data *data)
{
	char	**tmp_map;

	tmp_map = dup_map(data, data->map);
	if (!tmp_map)
		check_error(data, 1);
	fill(data, tmp_map, data->player_y, data->player_x);
	if (!check_fill(data, tmp_map))
	{
		free_array(tmp_map);
		check_error(data, 12);
	}
	free_array(tmp_map);
}
