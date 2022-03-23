# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:57:28 by bshintak          #+#    #+#              #
#    Updated: 2022/03/21 18:58:58 by bshintak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRC =	ft_lstnew			\
		ft_lstadd_front		\
		ft_lstsize			\
		ft_lstlast			\
		ft_lstadd_back		\
		ft_lstdelone		\
		ft_lstclear			\
		ft_lstiter			\
		ft_lstmap			\
		ft_calloc			\
		ft_memset

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
