/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:44:10 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/09 19:52:41 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	step;
	size_t	nstep;

	step = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[step] != '\0' && step < len)
	{
		nstep = 0;
		while (step + nstep < len && (needle[nstep] != '\0')
			&& (haystack[step + nstep] == needle[nstep]))
		{
			nstep ++;
			if (needle[nstep] == '\0')
			{
				return (&((char *)haystack)[step]);
			}
		}
		step ++;
	}
	return (0);
}
