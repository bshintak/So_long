/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:35:47 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/09 14:34:07 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(char **map)
{
	int		i;
	int		j;

	i = size_map(map, 1) - 1;
	while (map[i] && i > -1)
	{
		j = size_map(map, 2) - 1;
		while (map[i][j] != 0)
		{
			if (map[i][j] == 'P' && map[i][j + 1] == '0')
			{
				map[i][j + 1] = 'P';
				map[i][j] = '0';
			}
			else if (map[i][j] == 'P' && map[i][j + 1] == 'C')
			{
				map[i][j + 1] = 'P';
				map[i][j] = '0';
			}
			j--;
		}
		i--;
	}
	return (0);
}

int	move_left(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && map[i][j - 1] == '0')
			{
				map[i][j - 1] = 'P';
				map[i][j] = '0';
			}
			else if (map[i][j] == 'P' && map[i][j - 1] == 'C')
			{
				map[i][j - 1] = 'P';
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	move_down(char **map)
{
	int		i;
	int		j;

	i = size_map(map, 1) - 1;
	while (map[i] && i > -1)
	{
		j = size_map(map, 2) - 1;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && map[i + 1][j] == '0')
			{
				map[i + 1][j] = 'P';
				map[i][j] = '0';
			}
			else if (map[i][j] == 'P' && map[i + 1][j] == 'C')
			{
				map[i + 1][j] = 'P';
				map[i][j] = '0';
			}
			j--;
		}
		i--;
	}
	return (0);
}

int	move_up(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' && map[i - 1][j] == '0')
			{
				map[i - 1][j] = 'P';
				map[i][j] = '0';
			}
			else if (map[i][j] == 'P' && map[i - 1][j] == 'C')
			{
				map[i - 1][j] = 'P';
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (0);
}
