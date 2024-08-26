/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:08:40 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/13 15:26:54 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	stp;
	size_t	dlen;

	stp = 0;
	dlen = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dlen < dstsize && dest[dlen] != '\0')
		dlen++;
	while (stp + dlen < dstsize - 1 && src[stp] != '\0')
	{
		dest[stp + dlen] = src[stp];
		stp++;
	}
	if (stp + dlen < dstsize)
	{
		dest[stp + dlen] = '\0';
		stp++;
	}
	return (ft_strlen(src) + dlen);
}
