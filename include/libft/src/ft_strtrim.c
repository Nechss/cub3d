/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:40:18 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/23 19:58:28 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(const char *s, int c)
{
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*trim;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_set(set, s1[start]))
		start++;
	while (end > start && ft_set(set, s1[end]))
		end--;
	if (end >= start && s1[start] != '\0')
		len = (end - start + 1);
	else
		len = 0;
	trim = (char *)malloc(len + 1);
	if (!trim)
		return (0);
	ft_strlcpy(trim, s1 + start, len + 1);
	return (trim);
}
