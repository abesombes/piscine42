/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/07 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

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

int ft_find_next_prime(int nb)
{

	int i;

	i = nb;

	while (!ft_is_prime(i))
	{
		i++;
	}
	return (i);
}

int main (void)
{
	int nb;

	nb = 100002181;
	printf("\nft_find_next_prime(%i): %i", nb, ft_find_next_prime(nb));
}
