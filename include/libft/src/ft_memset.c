/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:10:28 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/09 16:19:52 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	cpy = s;
	i = 0;
	while (i < n)
	{
		cpy[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
