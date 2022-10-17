/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_collectible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:58:51 by bshintak          #+#    #+#             */
/*   Updated: 2022/07/28 15:05:51 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	help_get_out(int key, char **map, int i, int j)
{
	if (map[i][j - 1] == 'e' && key == key_A)
	{
		ft_printf("You win ​🥳​\n");
		free (map);
		exit (0);
	}
	else if (map[i][j + 1] == 'e' && key == key_D)
	{
		ft_printf("You win ​🥳​\n");
		free (map);
		exit (0);
	}
	else if (map[i + 1][j] == 'e' && key == key_S)
	{
		ft_printf("You win ​🥳​\n");
		free (map);
		exit (0);
	}
	else if (map[i - 1][j] == 'e' && key == key_W)
	{
		ft_printf("You win ​🥳​\n");
		free (map);
		exit (0);
	}
}

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
				help_get_out(key, map, i, j);
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

void	finish_exit(int key, char **map)
{
	if (num_of_itens(map) == 0)
		open_exist(map);
	get_out(key, map);
}
