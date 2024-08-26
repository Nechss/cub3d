/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:39:52 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/23 16:22:39 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;

	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	s = s + start;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s, len);
	substr[len] = '\0';
	return (substr);
}
