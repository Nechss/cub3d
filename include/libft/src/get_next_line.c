/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:10:44 by gperez-b          #+#    #+#             */
/*   Updated: 2023/11/30 14:10:49 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	len_s2 = 0;
	if (s2)
		len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (free (s1), NULL);
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		str[len_s1 + i] = s2[i];
	str[len_s1 + len_s2] = '\0';
	free(s1);
	return (str);
}

char	*newbuff(char *buff)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!new)
		return (free (buff), NULL);
	i++;
	j = 0;
	while (buff[i])
		new[j++] = buff[i++];
	new[j] = '\0';
	free(buff);
	return (new);
}

char	*copyline(char *buff)
{
	char	*line;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!buff[count])
		return (NULL);
	while (buff[count] && buff[count] != '\n')
		count++;
	if (ft_strchr(buff, '\n'))
		count++;
	line = (char *)malloc((count + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (buff[i] && i <= count)
	{
		line[i] = buff[i];
		i++;
	}
	line[count] = '\0';
	return (line);
}

char	*copyfile(int fd, char *buff)
{
	char	*str;
	int		count;

	str = malloc((1024 + 1) * sizeof(char));
	if (!str)
		return (free (buff), NULL);
	count = 1;
	while (!ft_strchr(buff, '\n') && count != 0)
	{
		count = read(fd, str, 1024);
		if (count == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		str[count] = '\0';
		buff = ft_strjoin_gnl(buff, str);
	}
	free (str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	if (fd < 0 || fd >= 1024)
		return (0);
	buff[fd] = copyfile(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = copyline(buff[fd]);
	if (!line)
		return (free (buff[fd]), buff[fd] = NULL, NULL);
	buff[fd] = newbuff(buff[fd]);
	return (line);
}
