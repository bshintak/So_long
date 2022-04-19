/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_collectible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:58:51 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/18 17:01:34 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_out(int key, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] && i > -1)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (map[i][j - 1] == 'e' && key == 0)
					exit (0);
				else if (map[i][j + 1] == 'e' && key == 2)
					exit (0);
				else if (map[i + 1][j] == 'e' && key == 1)
					exit (0);
				else if (map[i - 1][j] == 'e' && key == 13)
					exit (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	open_exist(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				map[i][j] = 'e';
				(*window()).exit = mlx_xpm_file_to_image((*window()).mlx,
						EXIT_2, &(*window()).size_x, &(*window()).size_y);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	num_of_itens(char **map)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				num++;
			j++;
		}
		i++;
	}
	return (num);
}

int	finish_exit(int key, char **map)
{
	if (num_of_itens(map) == 0)
		open_exist(map);
	get_out(key, map);
	return (0);
}

int	leave(void)
{
	exit(0);
}
