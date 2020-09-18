/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/14 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *buffer;
	int lowerbound;
	
	i = 0;
	if  (min >= max)
	{
		*range = NULL;
		return (0);	
	}
	if (!(buffer = malloc(sizeof(int) * (max - min))))
	{
		*range = NULL;
		return (-1);
	}
	*range = buffer;
	lowerbound = min;
	while (min < max)
	{
		buffer[i] = min;
		min++;
		i++;
	}
	return (max-lowerbound);
}

void 	ft_dump_array(int numbers[], int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		printf("%d", numbers[index]);
		if (index != size -1)
			printf(", ");
		index++;
	}

}

int 	main (void)
{
	int min;
	int max;
	int *range;
	int bound;
	
	min = -15;
	max = 7;
	bound = ft_ultimate_range(&range, min, max);
	printf("\nft_ultimate_range: %i\n", bound);
	ft_dump_array(range, bound);
	return (0);
}
