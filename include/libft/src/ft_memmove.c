/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:22:38 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/13 13:24:58 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cpy;
	size_t				i;

	cpy = dest;
	i = 0;
	if (!dest && !src && n)
		return (0);
	if (dest <= src)
	{
		while (i < n)
		{
			cpy[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			cpy[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
