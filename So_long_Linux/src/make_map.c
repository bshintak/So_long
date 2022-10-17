/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:31:51 by bshintak          #+#    #+#             */
/*   Updated: 2022/07/28 15:11:42 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	reset_img(char **map)
{
	char	*steps;

	steps = ft_itoa_lib((*(window())).count);
	mlx_clear_window((*window()).mlx, (*window()).win);
	put_images((*window()), map);
	mlx_string_put((*window()).mlx, (*window()).win, 20, 22,
		0x00FFFFFF, steps);
	free(steps);
	return (0);
}

void	player_img_key(int num)
{
	if (num == key_A)
		(*window()).player = mlx_xpm_file_to_image((*window()).mlx,
				PLAYER_LEFT, &(*window()).size_x, &(*window()).size_y);
	if (num == key_S)
		(*window()).player = mlx_xpm_file_to_image((*window()).mlx,
				PLAYER_DOWN, &(*window()).size_x, &(*window()).size_y);
	if (num == key_D)
		(*window()).player = mlx_xpm_file_to_image((*window()).mlx,
				PLAYER_RIGHT, &(*window()).size_x, &(*window()).size_y);
	if (num == key_W)
		(*window()).player = mlx_xpm_file_to_image((*window()).mlx,
				PLAYER_UP, &(*window()).size_x, &(*window()).size_y);
}

void	enemy_img_key(char **map, int num)
{
	if (num == key_D)
	{
		(*window()).enemy = mlx_xpm_file_to_image((*window()).mlx,
				ENEMY_RIGHT, &(*window()).size_x, &(*window()).size_y);
		enemy_move(map, key_D);
	}
	if (num == key_A)
	{
		(*window()).enemy = mlx_xpm_file_to_image((*window()).mlx,
				ENEMY_LEFT, &(*window()).size_x, &(*window()).size_y);
		enemy_move(map, key_A);
	}
	if (num == key_S)
	{
		(*window()).enemy = mlx_xpm_file_to_image((*window()).mlx,
				ENEMY_DOWN, &(*window()).size_x, &(*window()).size_y);
		enemy_move(map, key_S);
	}
	if (num == key_W)
	{
		(*window()).enemy = mlx_xpm_file_to_image((*window()).mlx,
				ENEMY_UP, &(*window()).size_x, &(*window()).size_y);
		enemy_move(map, key_W);
	}
}

int	move_player(int key, char **map)
{
	help_move_player1(key, map);
	help_move_player2(key, map);
	reset_img(map);
	finish_exit(key, map);
	touch_enemy(key, map);
	if (key == 65307)
	{
		ft_printf("Did you give up? 😲​​\n");
		free (map);
		exit (0);
	}
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
	mlx_key_hook((*window()).win, move_player, map);
	mlx_hook((*window()).win, 17, 0, leave,
		(void *)"Did you give up? 😲​​\n");
	mlx_loop_hook((*window()).mlx, reset_img, map);
	mlx_loop((*window()).mlx);
}
