# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 10:46:00 by bshintak          #+#    #+#              #
#    Updated: 2022/05/05 16:07:44 by bshintak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wall
RM			=	rm -f
MKD			=	mkdir
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit

SRC_NAME	=	create_map.c					\
				make_map.c						\
				make_map_utils.c				\
				size_of_map.c					\
				print_map1.c					\
				print_map2.c					\
				player_move.c					\
				finish_collectible.c			\
				enemy_move.c					\
				map_rules.c						\
				map_rules_surrounded_by_walls.c	\
				main.c

SRC		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ		=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))
DEPS	=	./Libft/libft.a ./Printf/libftprintf.a ./Gnl/get_next_line.a

SRC_PATH = ./src
OBJ_PATH = ./objects

all: $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(DEPS) $(OBJ_PATH) $(OBJ)
		$(CC) $(CFLAGS) $(DEPS) $(MLXFLAGS) $(OBJ) -o $(NAME)
		echo "\x1b[36m[SO_LONG COMPILED]\x1b[0m"

LIBFT_PATH	= ./Libft
./Libft/libft.a: $(shell make -C $(LIBFT_PATH) -q libft.a || echo force)
	make -C $(LIBFT_PATH)

LIBPF_PATH	= ./Printf
./Printf/libftprintf.a: $(shell make -C $(LIBPF_PATH) -q libftprintf.a || echo force)
	make -C $(LIBPF_PATH)

GET_PATH	= ./Gnl
./Gnl/get_next_line.a: $(shell make -C $(GET_PATH) -q get_next_line.a ||echo force)
	make -C $(GET_PATH)

$(OBJ_PATH):
	$(MKD) -p objects

norminette:
	echo "\x1b[32m[NORMINETTE OKAY]\x1b[0m"
	norminette | egrep -B1 'Error|Warning' | sed ''/Error/s//$(printf "\033[31m\033[4mError\033[0m")/'' | sed ''/Warning/s//$(printf "\033[33m\033[4mWarning\033[0m")/''

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(LIBPF_PATH)
	make clean -C $(GET_PATH)
	$(RM) -r $(OBJ_PATH)
	echo "\033[33mRemoving object files...\033[0m"

fclean: clean
		make fclean -C $(LIBFT_PATH)
		make fclean -C $(LIBPF_PATH)
		make fclean -C $(GET_PATH)
		$(RM) $(NAME)
		echo "\033[31mRemoving $(NAME)...\033[0m"

re: fclean all

.PHONY:	all clean fclean re force
