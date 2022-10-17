/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:57:27 by bshintak          #+#    #+#             */
/*   Updated: 2022/07/28 15:10:12 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_left(char **map, int i, int j)
{
	map[i][j] = '0';
	map[i][j - 1] = 'X';
}

void	enemy_right(char **map, int i, int j)
{
	map[i][j] = '0';
	map[i][j + 1] = 'X';
}

void	enemy_up(char **map, int i, int j)
{
	map[i][j] = '0';
	map[i - 1][j] = 'X';
}

void	enemy_down(char **map, int i, int j)
{
	map[i][j] = '0';
	map[i + 1][j] = 'X';
}

void	enemy_move(char **map, int op)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X' && map[i][j - 1] == '0' && op == key_A)
				enemy_left(map, i, j);
			if (map[i][j] == 'X' && map[i][j + 1] == '0' && op == key_D)
				enemy_right(map, i, j);
			else if (map[i][j] == 'X' && map[i + 1][j] == '0' && op == key_S)
				enemy_down(map, i, j);
			else if (map[i][j] == 'X' && map[i - 1][j] == '0' && op == key_W)
				enemy_up(map, i, j);
			j++;
		}
		i++;
	}
}
