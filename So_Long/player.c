/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:16 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/05 11:43:03 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
		move_player(data, data->player_y - 1, data->player_x, 1);
	else if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		move_player(data, data->player_y, data->player_x - 1, 2);
	else if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		move_player(data, data->player_y + 1, data->player_x, 3);
	else if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		move_player(data, data->player_y, data->player_x + 1, 4);
	if (keycode == XK_Escape)
		win_close(data);
	return (0);
}

void	move_player(t_data *data, int new_y, int new_x, int player_pos)
{
	int	y;
	int	x;

	data->player_pos = player_pos;
	y = data->player_y;
	x = data->player_x;
	if (data->map[new_y][new_x] == 'E' && data->cons_nbr == 0)
	{
		ft_printf("GG you win\n");
		free_all(data);
		exit(0);
	}
	else if (data->map[new_y][new_x] == '0' || data->map[new_y][new_x] == 'C')
	{
		data->map[y][x] = '0';
		if (data->map[new_y][new_x] == 'C')
			data->cons_nbr--;
		data->player_y = new_y;
		data->player_x = new_x;
		data->map[new_y][new_x] = 'P';
		ft_printf("Number of moves : %d\n", data->nb_move);
		data->nb_move++;
		put_on_map(data);
	}
}

int	win_close(t_data *data)
{
	ft_printf("Close the window\n");
	free_all(data);
	exit(0);
}
