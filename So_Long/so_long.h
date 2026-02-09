/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:02:19 by rbouquet          #+#    #+#             */
/*   Updated: 2024/10/05 10:02:58 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"

typedef struct s_data_mlx
{
	void	*ptr;
	void	*win;
	char	**map;

	int		img_size;
	int		line;
	int		column;
	int		nb_move;
	int		cons_nbr;
	int		exit_nbr;
	int		player_nbr;
	int		player_pos;
	int		x;
	int		y;

	void	*wall;
	void	*floor;
	void	*exit;
	void	*cons;
	void	*playerd;
	void	*playeru;
	void	*playerl;
	void	*playerr;

	int		player_x;
	int		player_y;
	int		next_x;
	int		next_y;

}			t_data;

//FLOOD_FILL
char		**dup_map(t_data *data, char **map);
void		fill(t_data *data, char **map, int y, int x);
bool		check_fill(t_data *data, char **tmp_map);
void		flood_fill(t_data *data);

//FREE_ERROR
void		free_sprites(t_data *data);
void		free_array(char **array);
void		free_all(t_data *data);

//IMAGE
void		*read_xpm(t_data *data, char *path);
void		image_init(t_data *data);
char		**malloc_map(t_data *data, char *map);
void		load_map(t_data *data, char *map);

//INIT_ALL
void		init_data_struct(t_data *data);
void		init_mlx(t_data *data);
void		put_player(t_data *data, int x, int y);
void		put_texture(t_data *data, int x, int y);
void		put_on_map(t_data *data);

//MAP_ERROR
void		wall_around_map(t_data *data);
void		check_map_size(t_data *data);
void		check_elements(t_data *data);
void		check_map_ext(t_data *data, char *map);
void		map_check(t_data *data, char *map);

//MAP_ERROR2
void		check_error(t_data *data, int nb);
void		check_map_error(int nb);

//PLAYER
int			key_handler(int keycode, t_data *data);
void		move_player(t_data *data, int new_y, int new_x, int player_pos);
int			win_close(t_data *data);

#endif
