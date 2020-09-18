/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/06 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>




int 	ft_is_prime(int nb)
{
	int i;

	i = 1;
	if (nb < 2)
		return 0;
	while (i * i < nb)
		i++;
	if (i * i  == nb)
		return 0;
	return 1;
}

int ft_find_next_prime(int nb)
{
	int j;
	int prev_prime;

	j = 2;
	while (j < nb)
	{
		if (ft_is_prime(j) == 1)
		{
		prev_prime = j;
		printf("\nprime %i - test prime: %i", j, ft_is_prime(j));
		}
	j++;
	}
	return j;
}

int 	main (void)
{
	int nb;

	nb = 16;
	printf("\nft_find_next_prime(%i): %i", nb, ft_find_next_prime(nb));
}

