/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:04:12 by gperez-b          #+#    #+#             */
/*   Updated: 2024/02/01 21:04:34 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
			j++;
		}
		i++;
	}
}
