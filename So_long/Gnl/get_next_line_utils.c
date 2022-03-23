/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:22:45 by bshintak          #+#    #+#             */
/*   Updated: 2022/03/21 10:21:11 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;
	char	*cp;

	i = 0;
	cp = (char *)(str);
	while (cp && *cp)
	{
		cp++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup_gnl(s1));
	else if (!s1 && s2)
		return (ft_strdup_gnl(s2));
	s1len = ft_strlen_gnl(s1);
	s2len = ft_strlen_gnl(s2);
	ptr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (NULL);
	while (i < (s1len + s2len + 1))
		ptr[i++] = 0;
	ft_memcpy(ptr, s1, s1len);
	ft_memcpy(ptr + s1len, s2, s2len);
	ptr[s1len + s2len] = '\0';
	return (ptr);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*str;
	int		len;

	if (s)
	{
		len = ft_strlen_gnl(s);
		if (!len)
			return (NULL);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_memcpy(str, s, len);
		*(str + len) = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	if (s)
	{
		tmp = (char *)(s);
		while (*tmp)
		{
			if (*tmp == (char)c)
				return (tmp);
			tmp++;
		}
		if (*tmp == c)
			return (tmp);
	}
	return (NULL);
}
