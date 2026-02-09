/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:32:27 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/02 14:13:26 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites(t_data *data)
{
	mlx_destroy_image(data->ptr, data->playeru);
	mlx_destroy_image(data->ptr, data->playerd);
	mlx_destroy_image(data->ptr, data->playerl);
	mlx_destroy_image(data->ptr, data->playerr);
	mlx_destroy_image(data->ptr, data->exit);
	mlx_destroy_image(data->ptr, data->cons);
	mlx_destroy_image(data->ptr, data->wall);
	mlx_destroy_image(data->ptr, data->floor);
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_all(t_data *data)
{
	if (data->playerd)
		free_sprites(data);
	if (data->map)
		free_array(data->map);
	if (data->win)
		mlx_destroy_window(data->ptr, data->win);
	if (data->ptr)
	{
		mlx_destroy_display(data->ptr);
		free(data->ptr);
	}
	if (data)
		free(data);
}
