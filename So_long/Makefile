# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 10:46:00 by bshintak          #+#    #+#              #
#    Updated: 2022/03/23 11:10:24 by bshintak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
MKD			=	mkdir
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit 

SRC_NAME	=	make_map.c	\
				create_map.c

SRC		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ		=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))
DEPS	=	./Libft/libft.a ./Printf/libftprintf.a ./Gnl/get_next_line.a

SRC_PATH = .
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

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(LIBPF_PATH)
	make clean -C $(GET_PATH)
	$(RM) -r $(OBJ_PATH)
	echo "\033[33mall $(NAME).o files are removed\033[0m"

fclean: clean
		make fclean -C $(LIBFT_PATH)
		make fclean -C $(LIBPF_PATH)
		make fclean -C $(GET_PATH)
		$(RM) $(NAME)
		echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY:	all clean fclean re force
