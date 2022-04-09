/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:48:52 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/09 16:50:41 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*window(void)
{
	static t_data	window;

	return (&window);
}

int	main(int argc, char **argv)
{
	char	**map;

	map = 0;
	if (argc < 2)
		return (ft_printf("\e[31mError\n\e[0mYou should choose a file 🥺\n"));
	if (argc > 2)
		return (ft_printf("\e[31mError\n\e[0mToo many arguments 🤡\n"));
	if (argc == 2)
		map = create_map(argv[1]);
/*
	if (check_elements_map(map) == 1)
		return (ft_printf("\e[31mError\n\e[0mIncomplete map 😒\n"));
	if (rectangular_map(map) == 1)
		return (ft_printf("\e[31mError\n\e[0mThe map is not rectangular 😫\n"));*/
	make_window(map);
}
