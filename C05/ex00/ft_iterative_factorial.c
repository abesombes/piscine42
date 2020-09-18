/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
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

int ft_iterative_factorial(int nb)
{
	int result;
	result = 1;
	if (nb < 0)
		return 0;
	if (nb == 0 || nb == 1)
		return 1;
	while (nb >= 2)
	{
		//printf("\nnb: %i - result: %i", nb, result);
		result = result * nb;
		nb--;
	}
	//printf("\nnb: %i - result: %i", nb, result);
	return result; 
}

int main (void)
{
	int nb;

	nb = 2;
	printf("\nft_iterative_factorial: %i", ft_iterative_factorial(nb));
}
