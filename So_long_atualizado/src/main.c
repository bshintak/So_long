/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:48:52 by bshintak          #+#    #+#             */
/*   Updated: 2022/05/05 16:08:44 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_data	*window(void)
{
	static t_data	window;

	return (&window);
}

void	error_msg(char *error, char **map)
{
	ft_printf(error);
	free (map);
	exit(1);
}

int	leave(char *msg)
{
	ft_printf(msg);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;

	map = 0;
	if (argc < 2)
		error_msg("\e[31mError\n\e[0mYou should choose a file 🥺\n", map);
	if (argc > 2)
		error_msg("\e[31mError\n\e[0mToo many arguments 🤡\n", map);
	if (argc == 2)
		map = create_map(argv[1]);
	if (map == NULL)
		error_msg("\e[31mError\n\e[0mSomething wrong 🙃​\n", map);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		error_msg("\e[31mError\n\e[0mInvalid file type 😡\n", map);
	check_map(map);
	check_elem(map);
	check_walls(map);
	element_invalid(map);
	make_window(map);
}
