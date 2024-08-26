/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:19:01 by gperez-b          #+#    #+#             */
/*   Updated: 2023/11/06 15:19:03 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_ct1(unsigned int n, int *count)
{
	char	num;

	if (n >= 10)
		ft_putnbr_ct1(n / 10, count);
	num = n % 10 + '0';
	write(1, &num, 1);
	(*count)++;
}

int	ft_putnbr_ct(int n)
{
	int				count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		ft_putnbr_ct1(-n, &count);
	}
	else
		ft_putnbr_ct1(n, &count);
	return (count);
}
