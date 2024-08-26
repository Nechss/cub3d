/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:05:36 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/09 19:13:58 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cpy;
	const unsigned char	*org;
	size_t				i;

	cpy = dst;
	org = src;
	i = 0;
	if (!dst && !src && n)
		return (0);
	while (i < n)
	{
		cpy[i] = org[i];
		i++;
	}
	return (dst);
}
