/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/08 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_triple(int a)
{
	printf("\n%i: triple = %i\n", a, (a*3));
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
		ft_putchar(nbr % 10 + '0');
}

void ft_foreach(int *tab, int length, void (*f)(int))
{
	int i;

	i = -1;
	while (++i < length)
	{
		(*f)(tab[i]);
		ft_putchar('\n');
	}
}

int 	main (void)
{
	int tab[5] = {1, 2, 3, 4, 5};

	ft_foreach(tab, 5, (void *)&ft_putnbr);
}
