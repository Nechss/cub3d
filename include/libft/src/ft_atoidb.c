/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:50:51 by gperez-b          #+#    #+#             */
/*   Updated: 2024/02/28 20:25:25 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atoidb(const char *str)
{
	double	rslt;
	double	dec;
	double	neg;

	rslt = 0;
	dec = 0.1;
	neg = 1;
	while ((*str > 8 && *str < 14) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg = -1;
	while (*str >= '0' && *str <= '9')
		rslt = (rslt * 10) + (*str++ - '0');
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			rslt = (rslt + ((*str++ - '0') * dec));
			dec = dec * 0.1;
		}
	}
	return (rslt * neg);
}
