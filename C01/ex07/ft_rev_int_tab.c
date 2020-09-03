/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/25 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1,&c,1);
}

void 	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	temp = 0;
	i = 0;
	while (i<=size/2)
	{
	temp = tab[i];
	tab[i]=tab[size-1-i];
	tab[size-1-i]=temp;
	i++;
	}
	printf("\n Range: %i %i %i %i %i %i %i\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
}

int 	main(void)
{	
	int range[7];
	int i;

	i = -1;
	while (++i<=6)
		range[i]=i;
	ft_rev_int_tab(range,7);
}
