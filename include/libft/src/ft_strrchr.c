/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:36:59 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/09 18:38:55 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	char		d;

	p = s;
	d = c;
	while (*s)
	{
		if (*s == d)
			p = s;
		s++;
	}
	if (*p == d)
		return ((char *)p);
	if (d == '\0')
		return ((char *)s);
	return (0);
}
