/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/04 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ft_putnbr(int nbr)
{
	int modulo;

	if (nbr > 9)
		ft_putnbr(nbr/10);
	modulo = nbr % 10 + '0';
	write(1, &modulo, 1);
}

int     *ft_range(int start, int end)
{
	int *range;
	int len;
	int i;

	len = (start > end ? start - end + 1: end - start + 1);
	if (!(range = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		range[i] = start;
		i++;
		(start > end)? start--: start++;
	}
	return (range);
}

int main(void)
{
	int a;
	int b;
	int *r;
	int len;
	int i;

	a = 0;
	b = -3;
	len = (a > b ? a - b + 1: b - a + 1);
	if (!(r = (int *)malloc(sizeof(int) * len)))
		return 0;
	r = ft_range(a, b);
	i = 0;
	while (i < len)
	{
		if (r[i] < 0)
		{
			write(1, "-", 1);
			ft_putnbr(-r[i]);
		}
		else
			ft_putnbr(r[i]);
		write(1, "\n", 1);
		i++;
	}
}
