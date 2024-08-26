/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:40:29 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/23 13:40:31 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(i + j + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	str[i + j] = '\0';
	return (str);
}
