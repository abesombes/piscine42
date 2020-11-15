/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/09 17:28:36 by abesombes        ###   ########.fr       */
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

int ft_is_even(int nb)
{
	if (nb % 2 == 0)
		return (1);
	else
		return (0);
}

int ft_is_not_ok(char *str)
{
	if (!str[0] || !str[1] || str[0] != 'o' || str[1] != 'k')
		return (1);
	else
		return (0);
}

int ft_any(char **tab, int(*f)(char *))
{
	int i;

	i = 0;
	printf("\n|%s|%s|%s|%s|", tab[0], tab[1], tab[2], tab[3]);
	while (tab[++i])
	{
		printf("\ntab[%i]: %s", i, tab[i]);
		if ((*f)(tab[i]) == 1)
			return (1);
	}
	return (0);
}

int 	main (int ac, char **av)
{
//	int tab[5] = {2, 4, 6, 7, 8};
	(void)ac;
	printf("\n%i", ft_any(av, (void *)&ft_is_not_ok));
}
