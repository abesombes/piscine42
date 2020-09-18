/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c		                                :+:      :+:    :+:   */
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

int	*ft_range(int min, int max)
{
	int index;
	int i;
	int *range;

	i = min;
	index = 0;
	if (!(range = (int *)malloc(sizeof(i) * (max - min))))
		return (NULL);
	while (i < max)
	{
		range[index] = i;
		i++;
		index++;
	}
	return (range);
}

int 	main (void)
{
	int *arraytoprint;
	int min;
	int max;
	int i;

	min = -15;
	max = -12;
	if (min > max)
			return (0);
	else 
		arraytoprint = ft_range(min, max);
	i = -1;
	while (++i < max - min)
		printf("\n%i",arraytoprint[i]);
	
	return (0);
}
