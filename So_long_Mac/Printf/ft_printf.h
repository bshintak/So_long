/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:44:15 by bshintak          #+#    #+#             */
/*   Updated: 2022/03/21 16:15:52 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft_printf.h"

int	ft_printf(const char *str, ...);
int	ft_base(unsigned long n, char *base);
int	ft_pointer(unsigned long n);

#endif
