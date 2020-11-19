/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:22:26 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/19 22:26:37 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compute(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	char			*str_nbr;
	unsigned int	len;
	unsigned int	nb;
	unsigned int	i;

	nb = (n < 0 ? -n : n);
	len = ft_compute(nb);
	i = 0;
	if (!(str_nbr = (char *)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	if (n < 0)
	{
		str_nbr[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb > 9)
	{
		str_nbr[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	str_nbr[i] = nb % 10 + 48;
	str_nbr[len] = '\0';
	return (str_nbr);
}
