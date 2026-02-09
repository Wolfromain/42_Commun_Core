/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:44:03 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/07 10:40:50 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*read_xpm(t_data *data, char *path)
{
	void	*sprite;

	sprite = mlx_xpm_file_to_image(data->ptr, path, &data->img_size,
			&data->img_size);
	if (!sprite)
		check_error(data, 4);
	return (sprite);
}

void	image_init(t_data *data)
{
	data->wall = read_xpm(data, "sprite/xpm/wall.xpm");
	data->floor = read_xpm(data, "sprite/xpm/floor.xpm");
	data->exit = read_xpm(data, "sprite/xpm/exit.xpm");
	data->cons = read_xpm(data, "sprite/xpm/cons.xpm");
	data->playerd = read_xpm(data, "sprite/xpm/down.xpm");
	data->playeru = read_xpm(data, "sprite/xpm/up.xpm");
	data->playerl = read_xpm(data, "sprite/xpm/left.xpm");
	data->playerr = read_xpm(data, "sprite/xpm/right.xpm");
}

char	**malloc_map(t_data *data, char *map)
{
	char	**map_array;
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	map_array = NULL;
	if (data->line != 0)
		map_array = malloc((data->line + 1) * sizeof(char *));
	if (!map_array)
		check_error(data, 1);
	i = -1;
	while (data->line > ++i)
	{
		map_array[i] = get_next_line(fd);
		if (!map_array[i])
		{
			free_array(map_array);
			check_error(data, 1);
		}
	}
	map_array[i] = NULL;
	close(fd);
	return (map_array);
}

void	load_map(t_data *data, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		check_error(data, 5);
	line = get_next_line(fd);
	if (line != 0)
		data->column = ft_strlen(line) - 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		data->line++;
	}
	free(line);
	close(fd);
	data->x = data->column * data->img_size;
	data->y = data->line * data->img_size;
	data->map = malloc_map(data, map);
}
