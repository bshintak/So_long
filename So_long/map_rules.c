/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:04:32 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/09 16:49:40 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_elements_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
					&& map[i][j] != 'C' && map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	rectangular_map(char **map)
{
	int	x;
	int	y;

	x = size_map(map, 1);
	y = size_map(map, 2);
	if (y == x)
		return (1);
	return (0);
}
