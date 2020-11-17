/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:41:01 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/16 17:37:35 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_iswhitespace(unsigned char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	res;
	int				sign;
	int				i;

	i = 0;
	sign = 1;
	while (ft_iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	res = 0;
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	if ((res == 2147483648 && sign == -1) || res <= 2147483647)
		return ((int)res * sign);
	if (res > 2147483648 && sign == -1)
		return (0);
	return (-1);
}
