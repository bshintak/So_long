/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:06:55 by bshintak          #+#    #+#             */
/*   Updated: 2022/04/18 15:38:12 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new || !lst)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	aux = ft_lstlast(*lst);
	aux->next = new;
	return (*lst);
}
