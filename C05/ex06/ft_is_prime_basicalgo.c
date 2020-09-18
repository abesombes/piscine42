/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
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
#include <stdbool.h>

int ft_is_prime(int nb)
{
	int i;
	int j;

	i = 2;
	if (nb < 2)
		return 0;
	while (i < nb)
	{
		j = 0;
		while (++j < nb)
		{
//		printf("\n i = %i et j = %i", i, j);
		if (i * j  == nb)
		return 0;
		}
	i++;
	}
	return 1;
}

int main (void)
{
	int nb;

	nb = 0;
	while (nb++ < 100)
		printf("\nft_is_prime(%i): %i", nb, ft_is_prime(nb));
}

