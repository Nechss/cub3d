/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:19:44 by gperez-b          #+#    #+#             */
/*   Updated: 2023/11/06 15:19:48 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_ct1(unsigned int n, int *count)
{
	char	num;

	if (n <= 9)
	{
		num = n + '0';
		write(1, &num, 1);
		(*count)++;
	}
	if (n > 9)
	{
		ft_putnbr_ct1(n / 10, count);
		ft_putnbr_ct1(n % 10, count);
	}
}

int	ft_putuns_ct(unsigned int n)
{
	int		count;

	count = 0;
	ft_putnbr_ct1(n, &count);
	return (count);
}
