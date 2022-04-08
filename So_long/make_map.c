/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:31:51 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/08 14:07:24 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*window(void)
{
	static t_data	window;

	return (&window);
}

void	reset_img(char **map)
{
	mlx_clear_window((*window()).mlx, (*window()).win);
	put_images((*window()), map);
}

void	player_img_key(int num)
{
	if (num == 0)
		(*window()).player = mlx_xpm_file_to_image((*window()).mlx,
				PLAYER_LEFT, &(*window()).size_x, &(*window()).size_y);
	if (num == 1)
		(*window()).player = mlx_xpm_file_to_image((*window()).mlx,
				PLAYER_DOWN, &(*window()).size_x, &(*window()).size_y);
	if (num == 2)
		(*window()).player = mlx_xpm_file_to_image((*window()).mlx,
				PLAYER_RIGHT, &(*window()).size_x, &(*window()).size_y);
	if (num == 13)
		(*window()).player = mlx_xpm_file_to_image((*window()).mlx,
				PLAYER_UP, &(*window()).size_x, &(*window()).size_y);
}

int	move_player(int key, char **map)
{
	if (key == 0)
	{
		player_img_key(0);
		move_left(map);
	}
	if (key == 1)
	{
		player_img_key(1);
		move_down(map);
	}
	if (key == 2)
	{
		player_img_key(2);
		move_right(map);
	}
	if (key == 13)
	{
		player_img_key(13);
		move_up(map);
	}
	reset_img(map);
	return (0);
}

void	make_window(char **map)
{
	(*window()).y = size_map(map, 1);
	(*window()).x = size_map(map, 2);
	(*window()).mlx = mlx_init();
	(*window()).win = mlx_new_window((*window()).mlx, ((*window()).x - 1) * 64,
			(*window()).y * 64, "so_long");
	(*window()).ground = mlx_xpm_file_to_image((*window()).mlx, GROUND,
			&(*window()).size_x, &(*window()).size_y);
	(*window()).wall = mlx_xpm_file_to_image((*window()).mlx, WALL,
			&(*window()).size_x, &(*window()).size_y);
	(*window()).player = mlx_xpm_file_to_image((*window()).mlx, PLAYER,
			&(*window()).size_x, &(*window()).size_y);
	(*window()).exit = mlx_xpm_file_to_image((*window()).mlx, EXIT,
			&(*window()).size_x, &(*window()).size_y);
	(*window()).collectible = mlx_xpm_file_to_image((*window()).mlx,
			COLLECTIBLE, &(*window()).size_x, &(*window()).size_y);
	(*window()).enemy = mlx_xpm_file_to_image((*window()).mlx, ENEMY,
			&(*window()).size_x, &(*window()).size_y);
	put_images((*window()), map);
	mlx_key_hook((*window()).win, move_player, map);
	mlx_loop((*window()).mlx);
	free(&window);
}
