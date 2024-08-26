/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:44:14 by gperez-b          #+#    #+#             */
/*   Updated: 2023/09/30 14:54:52 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_put_str(int n, int i)
{
	char	*str;

	if (n < 0)
	{
		i++;
		n = -n;
	}
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (str);
}

static char	*ft_minint(int n, int i)
{
	char	*str;
	char	*c;

	i++;
	if (n == -2147483648)
	{
		c = "-2147483648";
		str = (char *)malloc(i + 1);
	}
	else
	{
		c = "0";
		str = (char *)malloc(i + 1);
	}
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i] = c[i];
		i--;
	}
	return (str);
}

static int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_count_digits(n);
	if (n == 0 || n == -2147483648)
	{
		str = ft_minint(n, i);
		return (str);
	}
	str = ft_put_str(n, i);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	return (str);
}
