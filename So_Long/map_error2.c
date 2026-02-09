/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:06 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/05 10:44:00 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error(t_data *data, int nb)
{
	if (data->map)
		free_array(data->map);
	free(data);
	check_map_error(nb);
	if (nb == 1)
		ft_printf("Error\nMemory allocation failed\n");
	else if (nb == 2)
		ft_printf("Error\nProblem with the MLX\n");
	else if (nb == 3)
		ft_printf("Error\nCouldn't open the game window\n");
	else if (nb == 4)
		ft_printf("Error\nSprite loading problem\n");
	exit(EXIT_FAILURE);
}

void	check_map_error(int nb)
{
	if (nb == 5)
		ft_printf("Error\nCan't open your map file\n");
	else if (nb == 6)
		ft_printf("Error\nWrong number of row or column in your map\n");
	else if (nb == 7)
		ft_printf("Error\nThe map extension is wrong (.ber)\n");
	else if (nb == 8)
		ft_printf("Error\nPlease enter : ./so_long <path/to/map.ber>\n");
	else if (nb == 9)
		ft_printf("Error\nThere's a wall missing in your map\n");
	else if (nb == 10)
		ft_printf("Error\nWrong element in your map (PEC10)\n");
	else if (nb == 11)
		ft_printf("Error\nMissing or excessive Player, Exit or Collectible\n");
	else if (nb == 12)
		ft_printf("Error\nCan't access the exit or some collectibles\n");
	else if (nb == 13)
		ft_printf("Error\nThe map is too long");
}
