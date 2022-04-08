/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:48:52 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/08 11:49:13 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	make_window(map);
}
