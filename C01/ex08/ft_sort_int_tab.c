/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c         	                        :+:      :+:    :+:   */
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

void 	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int temp;
	int reshuffle;

	temp = 0;
	reshuffle = 1;
	while (reshuffle)
	{
		i = 0;
		reshuffle = 0;
		while (i<size-1)
		{
			if (tab[i]>tab[i+1])
			{
				reshuffle++;
				temp = tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=temp;
			}
		i++;
		}
	}
	printf("\nSorted Tab: %i %i %i %i %i %i %i\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
}

int 	main(void)
{	
	int range[7];

	range[0] = 5;
	range[1] = 3;
	range[2] = 4;
	range[3] = 1;
	range[4] = -1;
	range[5] = 0;
	range[6] = 2;
	ft_sort_int_tab(range,7);
}
