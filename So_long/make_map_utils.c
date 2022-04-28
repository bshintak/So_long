/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:06:20 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/28 10:43:24 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_touch_enemy(char *error, char **map)
{
	ft_printf(error);
	free (map);
	exit(0);
}	

void	help_move_player1(int key, char **map)
{
	if (key == 0)
	{
		player_img_key(0);
		move_left(map);
		enemy_img_key(map, 1);
	}
	else if (key == 1)
	{
		player_img_key(1);
		move_down(map);
		enemy_img_key(map, 3);
	}
}

void	help_move_player2(int key, char **map)
{
	if (key == 2)
	{
		player_img_key(2);
		move_right(map);
		enemy_img_key(map, 0);
	}
	else if (key == 13)
	{
		player_img_key(13);
		move_up(map);
		enemy_img_key(map, 2);
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
			if (map[i][j] == 'P' && map[i - 1][j] == 'X' && key == 13)
				error_touch_enemy("YOU LOST 😂​\n", map);
			if (map[i][j] == 'P' && map[i + 1][j] == 'X' && key == 1)
				error_touch_enemy("YOU LOST 😂​\n", map);
			if (map[i][j] == 'P' && map[i][j - 1] == 'X' && key == 0)
				error_touch_enemy("YOU LOST 😂​\n", map);
			if (map[i][j] == 'P' && map[i][j + 1] == 'X' && key == 2)
				error_touch_enemy("YOU LOST 😂​\n", map);
		}
	}
}
