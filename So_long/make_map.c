/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:31:51 by bshintak          #+#    #+#             */
/*   Updated: 2022/03/23 19:04:05 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	init(t_window *init)
// {
// 	init->map.map = malloc((init->size_y + 1) * sizeof(char *));
	
// }

int	make_window(t_window *window)
{
	ft_printf("aqui\n");
	// window->size_x = (ft_strlen(window->map.map[0]) - 1) * BLOCK_SIZE;
	// window->size_y = (window->map.lines) * BLOCK_SIZE;
	window->mlx = mlx_init();
	if (window->mlx == 0)
		return (-1);
	window->mlx_window = mlx_new_window(window->mlx, 1500, 1000, "hello");
	if (window->mlx_window == 0)
	{
		free(window);
		return (-1);
	}
	return (0);
}
#include <stdio.h>

void	find(t_window *image)
{
	image->img.player = mlx_xpm_file_to_image(image->mlx, PLAYER, &image->img.size_x, &image->img.size_y);
	image->img.ground = mlx_xpm_file_to_image(image->mlx, BLACK, &image->img.size_x, &image->img.size_y);
	image->img.wall = mlx_xpm_file_to_image(image->mlx, PURPLE, &image->img.size_x, &image->img.size_y);
	image->img.collectible = mlx_xpm_file_to_image(image->mlx, COLLECTIBLE, &image->img.size_x, &image->img.size_y);
	printf("images\n");
}

void	help_put_images(t_window *image, int width, int i, int j)
{
	printf("help put images\n");
	if (image->map.map[i][j] == '1')
		mlx_put_image_to_window(image->mlx, image->mlx_window, image->img.wall, width, i * BLOCK_SIZE);
	else if (image->map.map[i][j] == '0')
		mlx_put_image_to_window(image->mlx, image->mlx_window, image->img.ground, width, i * BLOCK_SIZE);
	else if (image->map.map[i][j] == 'P')
		mlx_put_image_to_window(image->mlx, image->mlx_window, image->img.player, width, i * BLOCK_SIZE);
	else if (image->map.map[i][j] == 'C')
		mlx_put_image_to_window(image->mlx, image->mlx_window, image->img.collectible, width, i * BLOCK_SIZE);
	// else if (image->map.map[i][j] == 'E')
	// 	mlx_put_image_to_window(image->mlx, image->mlx_window, image->img.exit, j * BLOCK_SIZE, i * BLOCK_SIZE);
}

int	put_images(t_window *image)
{
	int	i;
	int	j;
	int width;
	
	i = 0;
	j = 0;
	width = 0;
	printf("put_images\n");
	//image->map.map = malloc(sizeof(char *) * image->size_y + 1);
	while (image->map.map[i])
	{
		printf("first while put_images\n");
		//image->map.map[i] = malloc(sizeof(char) * image->size_x + 1);
		while (image->map.map[i][j] && image->map.map[i][j] != '\n')
		{
			printf("help\n");
			help_put_images(image, width, i, j);
			width += BLOCK_SIZE;
			j++;
		}
		printf("fds man\n");
		j = 0;
		width = 0;
		i++;
	}
	printf("saiuuuuu\n");
	return (0);
}

void	init_player(t_window *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int main(int argc, char **argv)
{
	// void		*mlx;
	// void		*mlx_window;
	// t_window	image[3];
	t_window	window;
	
	(void)argc;
	// window.map.fd = open(argv[1], O_RDONLY);
	// if (window.map.fd < 0)
	// 	ft_printf("\e[31mError: open failed\e[0m😐\n");
	create_map(argv[1], &window);
	//init_player(&window);
	make_window(&window);
	find(&window);
	put_images(&window);
	// ft_printf("passou\n");
	// mlx_put_image_to_window(mlx, mlx_window, image[1].img, 0, 0);
	// mlx_put_image_to_window(mlx, mlx_window, image[2].img, BLOCK_SIZE, 0);
	// mlx_loop_hook(window.mlx, &put_images, &window);
	mlx_loop(window.mlx);
	free(window.mlx);
}

