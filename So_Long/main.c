/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:25:18 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/07 09:52:22 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		check_error(data, 1);
	if (argc != 2)
		check_error(data, 9);
	init_data_struct(data);
	map_check(data, argv[1]);
	flood_fill(data);
	init_mlx(data);
	image_init(data);
	put_on_map(data);
	mlx_hook(data->win, 2, (1L << 0), key_handler, data);
	mlx_hook(data->win, 17, 0, win_close, data);
	mlx_loop(data->ptr);
	free_all(data);
	return (0);
}
