# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:57:28 by bshintak          #+#    #+#              #
#    Updated: 2022/04/19 16:09:38 by bshintak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRC =	ft_lstnew			\
		ft_lstlast			\
		ft_lstadd_back		\
		ft_lstdelone		\
		ft_lstclear			\
		ft_strncmp			\
		ft_strrchr			\
		ft_strdup_libft		\
		ft_strlen_libft		\
		ft_memcpy_libft		\
		ft_itoa_libft

CC =		gcc
RM =		rm -f
CFLAGS =	-Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)
bonus:	$(SRC:=.o)
		ar rc $(NAME) $(SRC:=.o)
