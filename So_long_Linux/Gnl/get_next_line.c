/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:35:26 by bshintak          #+#    #+#             */
/*   Updated: 2022/07/28 14:30:16 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*verif_buffer(char **storage, char **buffer, size_t buffer_len)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	i = ft_strlen_gnl(*storage);
	ret = (char *)malloc(sizeof(char) * (buffer_len + i + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, *storage, i);
	ft_memcpy(ret + i, *buffer, buffer_len);
	ret[i + buffer_len] = '\0';
	tmp = ft_strdup_gnl((*buffer) + buffer_len);
	if (*storage)
		free (*storage);
	(*storage) = tmp;
	return (ret);
}

static char	*put_storage(char **storage, char **buffer, size_t i)
{
	char	*tmp;
	char	*ret;

	ret = NULL;
	if (i <= 0)
	{
		if (i == 0 && *storage)
		{
			ret = (*storage);
			*storage = NULL;
		}
		return (ret);
	}
	(*buffer)[i] = '\0';
	tmp = ft_strchr(*buffer, '\n');
	if (tmp)
		ret = verif_buffer(storage, buffer, (tmp - *buffer) + 1);
	else
	{
		tmp = ft_strjoin(*storage, *buffer);
		if (*storage)
			free (*storage);
		*storage = tmp;
	}
	return (ret);
}

static char	*verif_storage(char **storage, int size)
{
	char	*tmp;
	char	*ret;
	int		i;

	if (size < 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i != size)
		ret[i] = (*storage)[i];
	ret[i] = '\0';
	tmp = ft_strdup_gnl(*storage + i);
	free (*storage);
	(*storage) = tmp;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*ret;
	size_t		i;

	if ((read(fd, 0, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (0);
	i = 1;
	ret = NULL;
	buffer = ft_strchr(storage, '\n');
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		while (ret == NULL && i > 0)
		{
			i = read(fd, buffer, BUFFER_SIZE);
			ret = put_storage(&storage, &buffer, i);
		}
		free (buffer);
		return (ret);
	}
	ret = verif_storage(&storage, (buffer - storage) + 1);
	return (ret);
}
