/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:04:32 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/19 14:17:08 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_elem(t_error elements, char **map)
{
	if (elements.collectible == 0)
		error_msg("\e[31mError\n\e[0mThe map has no collectible 🤔\n", map);
	else if (elements.player == 0)
		error_msg("\e[31mError\n\e[0mThe map has no player 🤔\n", map);
	else if (elements.exit == 0)
		error_msg("\e[31mError\n\e[0mThe map has no exit 🤔\n", map);
}

void	check_elem(char **map)
{
	t_error	elements;
	int		i;
	int		j;

	i = -1;
	elements.player = 0;
	elements.collectible = 0;
	elements.exit = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				elements.collectible++;
			else if (map[i][j] == 'E')
				elements.exit++;
			else if (map[i][j] == 'P')
				elements.player++;
		}
	}
	error_elem(elements, map);
}

void	error_map(t_error elements, char **map)
{
	if (elements.walls == 0)
		error_msg("\e[31mError\n\e[0mMAP IMCOMPLETE 💩\n", map);
}

void	check_map(char **map)
{
	t_error	elements;
	int		i;
	int		j;

	i = -1;
	elements.ground = 0;
	elements.walls = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				elements.walls++;
			else if (map[i][j] == '0')
				elements.ground++;
		}
	}
	error_map(elements, map);
}

void	element_invalid(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'X')
				error_msg("\e[31mError\n\e[0mInvalid element 😒\n", map);
			j++;
		}
		i++;
	}
}
