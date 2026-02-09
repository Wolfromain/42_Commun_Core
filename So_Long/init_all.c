/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:15:36 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/07 09:42:07 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data_struct(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_nbr = 0;
	data->exit_nbr = 0;
	data->column = 0;
	data->line = 0;
	data->cons_nbr = 0;
	data->nb_move = 1;
	data->player_pos = 3;
	data->img_size = 64;
}

void	init_mlx(t_data *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		check_error(data, 2);
	data->win = mlx_new_window(data->ptr, (data->column * data->img_size),
			(data->line * data->img_size), "The binding of Isaac");
	if (!data->win)
	{
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		check_error(data, 3);
	}
}

void	put_player(t_data *data, int x, int y)
{
	if (data->player_pos == 1)
		mlx_put_image_to_window(data->ptr, data->win,
			data->playeru, x * 64, y * 64);
	else if (data->player_pos == 2)
		mlx_put_image_to_window(data->ptr, data->win,
			data->playerl, x * 64, y * 64);
	else if (data->player_pos == 3)
		mlx_put_image_to_window(data->ptr, data->win,
			data->playerd, x * 64, y * 64);
	else if (data->player_pos == 4)
		mlx_put_image_to_window(data->ptr, data->win,
			data->playerr, x * 64, y * 64);
}

void	put_texture(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'P')
		put_player(data, x, y);
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->ptr, data->win,
			data->exit, x * 64, y * 64);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->ptr, data->win,
			data->cons, x * 64, y * 64);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->ptr, data->win,
			data->wall, x * 64, y * 64);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->ptr, data->win,
			data->floor, x * 64, y * 64);
}

void	put_on_map(t_data *data)
{
	int	y;
	int	x;

	y = data->line;
	while (y--)
	{
		x = data->column;
		while (x--)
			put_texture(data, y, x);
		x = 0;
	}
}
