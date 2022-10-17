/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:43:48 by bshintak          #+#    #+#             */
/*   Updated: 2021/12/02 13:58:13 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_letters(char let)
{
	if (let == 'c' || let == 's' || let == 'p' || let == 'd' || let == 'i'
		|| let == 'u' || let == 'x' || let == 'X' || let == '%')
		return (1);
	return (0);
}

int	ft_conversions(char conv, va_list args)
{
	int	counter;

	counter = 0;
	if (conv == 'c')
		counter += (ft_putchar((char)va_arg(args, int)));
	else if (conv == 's')
		counter += (ft_putstr(va_arg(args, char *)));
	else if (conv == 'p')
		counter += (ft_pointer(va_arg(args, unsigned long)));
	else if (conv == 'd' || conv == 'i')
		counter += (ft_putnumber(va_arg(args, int)));
	else if (conv == 'u')
		counter += (ft_base(va_arg(args, unsigned int), "0123456789"));
	else if (conv == 'x')
		counter += (ft_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (conv == 'X')
		counter += (ft_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (conv == '%')
		counter += (ft_putchar('%'));
	return (counter);
}

int	ft_start(const char *str, va_list args)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (!str)
			return (0);
		if (str[i] == '%')
		{
			i++;
			if (ft_letters(str[i]))
				counter += ft_conversions(str[i], args);
			else
				return (counter);
		}
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start (args, str);
	i = ft_start(str, args);
	va_end(args);
	return (i);
}
