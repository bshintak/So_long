/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:05:15 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/08 11:19:33 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_enemy(t_data img, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.ground, j, i);
	mlx_put_image_to_window(img.mlx, img.win, img.enemy, j, i);
}

void	help_put_images(t_data img, char **map, int i, int j)
{
	if (map[i][j] == '1')
		print_wall(img, i, j);
	if (map[i][j] == '0')
		print_ground(img, i, j);
	if (map[i][j] == 'P')
		print_player(img, i, j);
	if (map[i][j] == 'C')
		print_collectible(img, i, j);
	if (map[i][j] == 'E')
		print_exit(img, i, j);
	if (map[i][j] == 'X')
		print_enemy(img, i, j);
}

int	put_images(t_data img, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			help_put_images(img, map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
