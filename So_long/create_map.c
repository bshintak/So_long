/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:42:27 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/26 15:40:40 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**matrix(t_list *list, int i)
{
	t_list	*tmp;
	char	**mtx;
	int		j;

	j = 0;
	tmp = list;
	mtx = malloc(sizeof(char *) * (i + 1));
	if (!mtx)
		return (0);
	while (tmp != 0)
	{
		mtx[j] = tmp->content;
		tmp = tmp->next;
		j++;
	}
	mtx[j] = 0;
	return (mtx);
}

char	**create_map(char *path)
{
	int		fd;
	int		i;
	t_list	*mapinha;
	char	**dora_map;

	i = 0;
	mapinha = NULL;
	fd = open(path, O_RDONLY);
	while (ft_lstadd_back(&mapinha, ft_lstnew(get_next_line(fd))))
		i++;
	dora_map = matrix(mapinha, i);
	i = 0;
	ft_lstclear(&mapinha, 0);
	close(fd);
	return (dora_map);
}
