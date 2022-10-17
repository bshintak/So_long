/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:06:20 by bshintak          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:31 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_touch_enemy(char *error, char **map)
{
	ft_printf(error);
	free (map);
	exit(0);
}	

void	help_move_player1(int key, char **map)
{
	if (key == key_A)
	{
		player_img_key(key_A);
		move_left(map);
		enemy_img_key(map, key_D);
	}
	else if (key == key_S)
	{
		player_img_key(key_S);
		move_down(map);
		enemy_img_key(map, key_W);
	}
}

void	help_move_player2(int key, char **map)
{
	if (key == key_D)
	{
		player_img_key(key_D);
		move_right(map);
		enemy_img_key(map, key_A);
	}
	else if (key == key_W)
	{
		player_img_key(key_W);
		move_up(map);
		enemy_img_key(map, key_S);
	}
}

void	touch_enemy(int key, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && map[i - 1][j] == 'X' && key == key_W)
				error_touch_enemy("YOU LOST 😂​\n", map);
			if (map[i][j] == 'P' && map[i + 1][j] == 'X' && key == key_S)
				error_touch_enemy("YOU LOST 😂​\n", map);
			if (map[i][j] == 'P' && map[i][j - 1] == 'X' && key == key_A)
				error_touch_enemy("YOU LOST 😂​\n", map);
			if (map[i][j] == 'P' && map[i][j + 1] == 'X' && key == key_D)
				error_touch_enemy("YOU LOST 😂​\n", map);
		}
	}
}
