/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:42:27 by bshintak          #+#    #+#             */
/*   Updated: 2022/03/23 19:06:18 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_lines(char *map)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_printf("\e[31mError: open failed\e[0m😐\n");
	else
		map = get_next_line(fd);
		while (map != 0)
		{
			count++;
			free(map);
			map = get_next_line(fd);
		}
		close(fd);
	return (count);
}

// void	put_map(int x, int y, int i, t_window *map)
// {
// 	char	*line;

// 	line = get_next_line(map->map.fd);
// 	while (line != NULL)
// 	{
// 		map->map.map[x] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
// 		if (!map->map.map[x])
// 			return (free(map->map.map));
// 		while (line[i] != '\0')
// 			map->map.map[x][y++] = line[i++];
// 		map->map.map[x++][y] = '\0';
// 		y = 0;
// 		i = 0;
// 		free(line);
// 		line = get_next_line(map->map.fd);
// 	}
// 	map->map.map[x] = NULL;
// }


void	put_input_in_map(int row, int column, int i, t_window *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			return (free(data->map.map));
		while (line[i] != '\0')
			data->map.map[row][column++] = line[i++];
		data->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
}

void	create_map(char	*path, t_window *map)
{
	// int		x;
	// int		i;
	// int		y;

	// i = 0;
	// x = 0;
	// y = 0;
	// map->map.lines = number_of_lines(path);
	// map->map.path = path;
	// map->map.map = ft_calloc(map->map.lines + 1, sizeof(char *));
	// if (!(map->map.map))
	// 	return ;
	// map->map.fd = open(path, O_RDONLY);
	// if (map->map.fd < 0)
	// 	ft_printf("\e[31mError: open failed\e[0m😐\n");
	// else
	// {
	// 	put_map(x, y, i, map);
	// 	close(map->map.fd);
	// }
	int		fd;
	int		count;
	t_list	*mapinha;
	int		row;
	int		i;
	int		column;

	i = 0;
	row = 0;
	column = 0;
	(void)count;
	fd = 0;
	map->read = 0;
	mapinha = map->read;
	if (!map->map.map)
		return ;
	fd = open(path, O_RDONLY);
	while (ft_lstadd_back(&mapinha, ft_lstnew(get_next_line(fd))))
		;
	if (map->map.fd < 0)
		ft_printf("\e[31mError: open failed\e[0m\n");
	else
		put_input_in_map(row, column, i, map);
	close(fd);
}
