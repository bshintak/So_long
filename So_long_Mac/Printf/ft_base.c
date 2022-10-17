/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:20:45 by bshintak          #+#    #+#             */
/*   Updated: 2021/11/30 14:54:38 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_len_base(unsigned long n, int base)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long n, char *base)
{
	char			*str;
	unsigned int	len;
	unsigned long	len_base;

	if (n == 0)
		return (ft_strdup("0"));
	len_base = ft_strlen(base);
	len = ft_len_base(n, len_base);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (n > 0)
	{
		str[len] = base[n % len_base];
		n = (n / len_base);
		len--;
	}
	return (str);
}

int	ft_base(unsigned long n, char *base)
{
	char	*str;
	int		final;

	final = 0;
	str = ft_itoa_base(n, base);
	final = ft_putstr(str);
	free (str);
	return (final);
}

int	ft_pointer(unsigned long n)
{
	char	*str;
	int		counter;

	counter = 0;
	if (n == 0)
		counter += ft_putstr("0x0");
	else if (n != 0)
	{
		counter += ft_putstr("0x");
		str = ft_itoa_base(n, "0123456789abcdef");
		counter += ft_putstr(str);
		free (str);
	}
	return (counter);
}
