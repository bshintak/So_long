/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:06:43 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/09 16:41:17 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "../So_long/Gnl/get_next_line.h"
# include "../So_long/Printf/ft_printf.h"
# include "../So_long/Libft/libft.h"

# define PLAYER "./images/mike_first.xpm"
# define PLAYER_RIGHT "./images/mike_right.xpm"
# define PLAYER_LEFT "./images/mike_left.xpm"
# define PLAYER_UP "./images/mike_up.xpm"
# define PLAYER_DOWN "./images/mike_down.xpm"

# define WALL "./images/wall.xpm"
# define EXIT "./images/exit.xpm"
# define EXIT_2 "./images/exit2.xpm"
# define GROUND "./images/ground.xpm"
# define COLLECTIBLE "./images/cilindro_grito.xpm"

# define ENEMY "./images/boo_down.xpm"
# define ENEMY_RIGHT "./images/boo_right.xpm"
# define ENEMY_LEFT "./images/boo_left.xpm"
# define ENEMY_UP "./images/boo_up.xpm"
# define ENEMY_DOWN "./images/boo_down.xpm"

// typedef struct	s_data 
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// typedef struct s_map
// {
// 	char	**map;
// 	char	*path;
// 	int		lines;
// 	int		fd;
// }			t_map;

// typedef struct	s_window
// {
// 	t_list	*make_map;
// 	void	*mlx;
// 	void	*image;
// 	void	*mlx_window;
// 	int		size_x;
// 	int		size_y;
// 	int		p_i;
// 	int		p_j;
// 	char	**map;
// 	t_img	img;
// 	t_map	fds;
// }				t_window;

typedef struct s_data
{
	int		y;
	int		x;
	void	*mlx;
	void	*win;
	void	*img;
	void	*player;
	void	*wall;
	void	*collectible;
	void	*ground;
	void	*exit;
	void	*enemy;
	int		size_x;
	int		size_y;
	char	**map;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*	STATIC	*/
t_data	*window(void);

/*	MAKE MAP	*/
char	**create_map(char *path);
void	make_window(char **map);

/*	PRINT IMAGES	*/	
void	print_exit(t_data img, int i, int j);
void	print_wall(t_data img, int i, int j);
void	print_enemy(t_data img, int i, int j);
void	print_ground(t_data img, int i, int j);
void	print_player(t_data img, int i, int j);
void	print_collectible(t_data img, int i, int j);

/*	MOVE PLAYER	*/
int		move_player(int key, char **map);
int		move_right(char **map);
int		move_left(char **map);
int		move_up(char **map);
int		move_down(char **map);

/*	RULES	*/
int		check_elements_map(char **map);
int		rectangular_map(char **map);

int		size_map(char **map, int option);
int		put_images(t_data img, char **map);

int		num_of_itens(char **map);
int		finish_exit(char **map);
void	reset_img(char **map);
int		leave(void);

int		get_out(char **map);
int		enemy_move(char **map, int option);
void	enemy_img_key(char **map, int num);
void	player_img_key(int num);

int		help_move_player1(int key, char **map);
int		help_move_player2(int key, char **map);

#endif
