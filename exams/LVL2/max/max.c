/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c	            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/27 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int max(int *tab, unsigned int len)
{
	unsigned int i;
	int max;

	max = 0;
	i = 0;
	if (!len)
		return (0);
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return max;
}

int main(void)
{

	int tab[6] = {5, 4, 7, 1 , 8, 6};
	int tabsize = 6;

	printf("\nMAX: %i", max(tab, tabsize));
}
