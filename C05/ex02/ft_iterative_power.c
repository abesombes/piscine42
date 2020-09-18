/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
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

void ft_putchar (char c)
{
	write(1, &c, 1);
}

int ft_iterative_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return 0;
	if (power == 0)
		return 1;
	while (power >= 1)
	{
		result = result * nb;
		power--;
	}
	return result; 
}

int main (void)
{
	int nb;
	int power;

	nb = 3;
	power = 5;
	printf("\nft_iterative_power(%i, %i): %i", nb, power, ft_iterative_power(nb, power));
}
