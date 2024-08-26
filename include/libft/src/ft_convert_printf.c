/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:18:31 by gperez-b          #+#    #+#             */
/*   Updated: 2023/11/06 15:18:33 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert_printf(va_list args, const char mod)
{
	if (mod == 'c')
		return (ft_putchar_ct(va_arg(args, int)));
	else if ((mod == 'd') || (mod == 'i'))
		return (ft_putnbr_ct(va_arg(args, int)));
	else if (mod == 's')
		return (ft_putstr_ct(va_arg(args, char *)));
	else if (mod == 'p')
		return (ft_putptr_ct(va_arg(args, void *)));
	else if (mod == 'u')
		return (ft_putuns_ct(va_arg(args, unsigned int)));
	else if (mod == 'x')
		return (ft_puthex_ct((va_arg(args, int)), "0123456789abcdef"));
	else if (mod == 'X')
		return (ft_puthex_ct((va_arg(args, int)), "0123456789ABCDEF"));
	else if (mod == '%')
		return (ft_putchar_ct('%'));
	return (0);
}
