/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:50:51 by gperez-b          #+#    #+#             */
/*   Updated: 2024/01/24 17:55:53 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	rslt;
	int	neg;

	neg = 1;
	rslt = 0;
	while ((*str > 8 && *str < 14) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg = -1;
	while (*str >= '0' && *str <= '9')
		rslt = (rslt * 10) + (*str++ - '0');
	return (rslt * neg);
}
