/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c		                                :+:      :+:    :+:   */
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

int ft_triple(int a)
{
	printf("\n%i: triple = %i\n", a, (a*3));
	return (a*3);
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

int *ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *res;

	res = (int *)malloc(sizeof(int)*length);

	i = -1;
	while (++i < length)
		res[i] = (*f)(tab[i]);
	return (res);
}

int 	main (void)
{
	int i;
	int tab[5] = {1, 2, 3, 4, 5};
	int *res;

	res = ft_map(tab, 5, (void *)&ft_triple);
	i = -1;
	while (++i < 5)
		printf("\nres[0]: %i", res[i]);
}
