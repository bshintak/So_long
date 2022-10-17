/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:03:33 by bshintak          #+#    #+#             */
/*   Updated: 2022/08/02 17:44:21 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_exit(t_data img, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.ground, j, i);
	mlx_put_image_to_window(img.mlx, img.win, img.exit, j, i);
}

void	print_collectible(t_data img, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.ground, j, i);
	mlx_put_image_to_window(img.mlx, img.win, img.collectible, j, i);
}

void	print_player(t_data img, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.ground, j, i);
	mlx_put_image_to_window(img.mlx, img.win, img.player, j, i);
}

void	print_wall(t_data img, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.wall, j, i);
}

void	print_ground(t_data img, int i, int j)
{
	i = i * 64;
	j = j * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.ground, j, i);
}
