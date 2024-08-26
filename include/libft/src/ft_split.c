/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:19:17 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/30 16:29:00 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_words(char **rslt)
{
	int	i;

	i = 0;
	while (rslt[i])
	{
		free(rslt[i]);
		i++;
	}
	free(rslt);
}

static char	*strndup2(const char *s, size_t n)
{
	char	*rslt;
	char	*dest;

	rslt = malloc(n + 1);
	if (!rslt)
		return (NULL);
	dest = rslt;
	while (n--)
		*dest++ = *s++;
	*dest = '\0';
	return (rslt);
}

static int	split_words(char const *s, char c, char **rslt)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			rslt[i] = strndup2(s - len, len);
			if (!rslt[i])
				return (-1);
			i++;
		}
		else
			s++;
	}
	return (i);
}

static int	count_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		wordn;
	char	**rslt;
	int		i;

	wordn = count_words(s, c);
	rslt = malloc(sizeof(char *) * (wordn + 1));
	if (!rslt)
		return (NULL);
	i = split_words(s, c, rslt);
	if (i == -1)
	{
		free_words(rslt);
		return (NULL);
	}
	rslt[i] = NULL;
	return (rslt);
}
