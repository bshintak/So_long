/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:00:26 by bshintak          #+#    #+#             */
/*   Updated: 2022/03/21 16:15:18 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	absolute_value(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_intlen(long int n)
{
	int	len;

	if (n <= 0)
	{
		n = -n;
		len = 1;
	}
	else
		len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long int n)
{
	int		len;
	char	*ptr;

	len = ft_intlen(n);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n < 0)
		ptr[0] = '-';
	if (n == 0)
		ptr[0] = '0';
	while (n != 0)
	{
		ptr[len - 1] = absolute_value(n % 10) + '0';
		n /= 10;
		len--;
	}
	return (ptr);
}

int	ft_putnumber(int nb)
{
	char	*str;
	int		counter;

	counter = 0;
	str = ft_itoa(nb);
	counter += ft_putstr(str);
	free (str);
	return (counter);
}
