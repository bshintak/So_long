/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:06:43 by bshintak          #+#    #+#             */
/*   Updated: 2022/07/28 15:10:51 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include "Gnl/get_next_line.h"
# include "Printf/ft_printf.h"
# include "Libft/libft.h"

//# define malloc(x) NULL

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
	int		count;
}				t_data;

typedef struct s_error
{
	int	player;
	int	collectible;
	int	exit;
	int	walls;
	int	ground;
}				t_error;

enum e_keys
{
	key_A = 97,
	key_S = 115,
	key_D = 100,
	key_W = 119,
};
/*	STATIC	*/
t_data	*window(void);

/*	MAKE MAP	*/
void	make_window(char **map);
char	**create_map(char *path);

/*	PRINT IMAGES	*/	
void	print_exit(t_data img, int i, int j);
void	print_wall(t_data img, int i, int j);
void	print_enemy(t_data img, int i, int j);
void	print_ground(t_data img, int i, int j);
void	print_player(t_data img, int i, int j);
void	print_collectible(t_data img, int i, int j);

/*	MOVE	*/
void	move_right(char **map);
void	move_left(char **map);
void	move_up(char **map);
void	move_down(char **map);
int		move_player(int key, char **map);
void	enemy_move(char **map, int op);
void	help_move_player1(int key, char **map);
void	help_move_player2(int key, char **map);
void	enemy_left(char **map, int i, int j);
void	enemy_right(char **map, int i, int j);
void	enemy_up(char **map, int i, int j);
void	enemy_down(char **map, int i, int j);

/*	RULES	*/
void	check_elem(char **map);
void	check_walls(char **map);

/*	ERROR	*/
void	error_msg(char *error, char **map);

/*	IMAGE PLAYER AND ENEMY	*/
int		reset_img(char **map);
void	player_img_key(int num);
void	enemy_img_key(char **map, int num);
void	help_enemy_img_key1(int num, char **map);
void	help_enemy_img_key2(int num, char **map);
void	help_enemy_img_key3(int num, char **map);
void	help_enemy_img_key4(int num, char **map);
void	put_images(t_data img, char **map);

/*	LEAVE GAME	*/
int		leave(char *msg);
int		num_of_itens(char **map);
void	finish_exit(int key, char **map);
void	touch_enemy(int key, char **map);

/*	CHECK MAP	*/
void	check_map(char **map);
void	element_invalid(char **map);

/*	SIZE	*/
int		size_map(char **map, int option);

#endif
