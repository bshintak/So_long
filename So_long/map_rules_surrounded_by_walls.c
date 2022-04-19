/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules_surrounded_by_walls.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:32:28 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/18 18:23:41 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_top(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (map[i][++j] != '\n')
	{
		if (map[i][j] != '1')
			return (1);
	}
	return (0);
}

int	check_bottom(char **map)
{
	int	i;
	int	j;

	i = size_map(map, 1) - 1;
	j = -1;
	while (map[i][++j] != '\n')
	{
		if (map[i][j] != '1')
			return (1);
	}
	return (0);
}

int	check_borders(char **map)
{
	int	i;
	int	line_len;
	int	last_line;

	i = 0;
	line_len = size_map(map, 2) - 2;
	last_line = size_map(map, 1) - 1;
	while (i <= last_line)
	{
		if (map[i][0] != '1' || map[i][line_len] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_walls(char **map)
{
	if ((check_top(map) == 1) || (check_bottom(map) == 1)
		|| (check_borders(map) == 1))
		error_msg("\e[31mError\n\e[0mThe walls are not correct 🥱\n", map);
}
