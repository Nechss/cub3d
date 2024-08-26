/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:24:48 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/13 16:44:54 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	stp;

	stp = 0;
	while (stp < n)
	{
		if (((unsigned char *)s)[stp] == (unsigned char)c)
			return (&((unsigned char *)s)[stp]);
		stp++;
	}
	return (NULL);
}
