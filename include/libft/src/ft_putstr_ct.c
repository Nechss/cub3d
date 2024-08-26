/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:19:34 by gperez-b          #+#    #+#             */
/*   Updated: 2023/11/06 15:19:36 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_ct(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
}
