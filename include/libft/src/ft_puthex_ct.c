/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:18:51 by gperez-b          #+#    #+#             */
/*   Updated: 2023/11/06 15:18:53 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putbase(unsigned int nbr, char *base, int *count)
{
	if (nbr >= 16)
		ft_putbase(nbr / 16, base, count);
	write(1, &base[nbr % 16], 1);
	(*count)++;
}

int	ft_puthex_ct(int nbr, char *base)
{
	int				count;

	count = 0;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	ft_putbase(nbr, base, &count);
	return (count);
}
