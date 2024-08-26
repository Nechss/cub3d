/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:54:52 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/09 18:07:14 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
	{
		while (src[len] != '\0')
			len++;
		return (len);
	}
	while (len < dstsize - 1 && src[len] != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	if (len < dstsize)
		dest[len] = '\0';
	while (src[len] != '\0')
		len++;
	return (len);
}
