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

int 	ft_sqrt(int nb)
{
	int i;

	i = 1;

	if (nb <= 0)
	return 0;

	while (i <= nb)
	{
		if  ((i * i) == nb)
		return i;
		i++;
	}
	return 0;
}


int 	ft_rounded_sqrt(int nb)
{
	int i;

	i = 1;

	if (nb <= 0)
	return 0;

	while (i * i < nb)
		i++;
	return i;
}


int 	ft_is_prime(int nb)
{
	int i;
	int upperb;

	if (nb < 2)
		return 0;
	else if (nb == 2)
		return 1;
	upperb = ft_rounded_sqrt(nb);
	i = 2;
	while (i <= upperb)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int main (void)
{
	int nb;

	nb = 0;
	while (nb++ < 10000)
		{
//		printf("\nft_rounded_sqrt(%i): %i", nb, ft_rounded_sqrt(nb));
		if (ft_is_prime(nb))	
		printf("\nft_is_prime(%i): %i", nb, 1);
		}
}

