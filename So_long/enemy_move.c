/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:57:27 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/26 10:50:38 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	enemy_move(char **map, int option)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X' && map[i][j - 1] == '0' && option == 1)
				enemy_left(map, i, j);
			if (map[i][j] == 'X' && map[i][j + 1] == '0' && option == 2)
				enemy_right(map, i, j);
			else if (map[i][j] == 'X' && map[i + 1][j] == '0' && option == 3)
				enemy_down(map, i, j);
			else if (map[i][j] == 'X' && map[i - 1][j] == '0' && option == 4)
				enemy_up(map, i, j);
			j++;
		}
		i++;
	}
}
