/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c	                                :+:      :+:    :+:   */
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


int ft_a_minus_b(int a, int b)
{
	return (a - b);
}

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;

	i = -1;
	printf("\n|%i|%i|%i|%i|%i|%i", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	while (++i < length - 1)
	{
		printf("\ntab[%i]: %i", i, tab[i]);
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
	}
	return (1);
}

int 	main (void)
{
	int tab[6] = {-1, 3, 3, 5, 6, 7};
	printf("\nis sorted? %i", ft_is_sort(tab, 6, &ft_a_minus_b));
}
