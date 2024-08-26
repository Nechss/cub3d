/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:19:19 by gperez-b          #+#    #+#             */
/*   Updated: 2023/11/07 15:38:12 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putptr(unsigned long long adr, int *count)
{
	static char	base[] = "0123456789abcdef";

	if (adr >= 16)
		ft_putptr(adr / 16, count);
	write(1, &base[adr % 16], 1);
	(*count)++;
}

int	ft_putptr_ct(void *adr)
{
	int	count;

	count = 0;
	if (adr == NULL)
		return (write(1, "0x0", 3));
	count += write(1, "0x", 2);
	ft_putptr((unsigned long long)adr, &count);
	return (count);
}
