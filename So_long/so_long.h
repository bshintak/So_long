/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:06:43 by bshintak          #+#    #+#             */
/*   Updated: 2022/03/23 19:00:20 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include "../So_long/Gnl/get_next_line.h"
#include "../So_long/Printf/ft_printf.h"
#include "../So_long/Libft/libft.h"

# define BLACK "\033[0;30m"
# define PURPLE "\033[1;35m"
# define PLAYER "./images/mike.xpm"
# define COLLECTIBLE "./images/cilindro_grito.xpm"
# define BLOCK_SIZE 64

typedef struct s_img
{
	int		size_x;
	int		size_y;
	void	*player;
	void	*wall;
	void	*collectible;
	void	*ground;
	void	*exit;
}			t_img;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	*path;
	char	**map;
	int		lines;
	int		fd;
}			t_map;

typedef struct	s_window
{
	void	*mlx;
	void	*mlx_window;
	int		size_x;
	int		size_y;
	int		p_i;
	int		p_j;
	t_img	img;
	t_map	map;
	t_list	*read;
}				t_window;

void	create_map(char	*path, t_window *map);
int		number_of_lines(char *map);


#endif
