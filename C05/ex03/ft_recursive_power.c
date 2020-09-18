/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
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

int ft_recursive_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return 0;
	if (power == 0)
		return 1;
	if (power >= 1)
		result = ft_recursive_power(nb, power - 1) * nb;
	return result; 
}

int main (void)
{
	int nb;
	int power;

	nb = 4;
	power = 5;
	printf("\nft_recursive_power(%i, %i): %i", nb, power, ft_recursive_power(nb, power));
}

