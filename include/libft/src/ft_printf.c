/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:16:52 by gperez-b          #+#    #+#             */
/*   Updated: 2023/11/06 15:21:49 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_convert_printf(args, *format);
		}
		else
			count += ft_putchar_ct(*format);
		format++;
	}
	va_end(args);
	return (count);
}
