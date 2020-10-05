/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c        	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/03 17:28:36 by abesombes        ###   ########.fr       */
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

int ft_maxdiff(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1 - nbr2);
	else
		return (nbr2 - nbr1);
}

int *ft_rrange2(int start, int end)
{
	int i;
	int j;
	int size;
	int *range;

	if (!(range=(int*)malloc(sizeof(int) * (ft_maxdiff(end, start) + 1))))
		return 0;
	size = ft_maxdiff(end, start);
	i = end;
	j = 0;
	while (j <= size)
	{
		range[j] = i;
		if (end > start)
			i--;
		else
			i++;
		j++;
	}
	return (range);
}

int     *ft_rrange(int start, int end)
{
	int	*r;
	int	len;

	len = (end >= start) ? end - start + 1 : start - end + 1;
	if (!(r = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	 while (len--)
		 r[len] = (end >= start) ? start++ : start--;
	return (r);
}

int main(void)
{
	int int1;
	int int2;
	int *int_range;
	int i;

	int1 = 0;
	int2 = -3;
	if (!(int_range=(int*)malloc(sizeof(int) * (ft_maxdiff(int1, int2) + 1))))
		return 0;
	i = 0;
	int_range = ft_rrange(int1, int2);
	while (i < ft_maxdiff(int1, int2) + 1)
	{
		if (int_range[i] < 0)
		{
			write(1, "-", 1);
			ft_putnbr(-int_range[i]);
		}
		else
			ft_putnbr(int_range[i]);
		i++;
		write(1, "\n", 1);
	}
}
