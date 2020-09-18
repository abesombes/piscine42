/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
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

int ft_recursive_factorial(int nb)
{
	int result;

	result = 0;
	if (nb < 0)
		return 0;
	if (nb == 0 || nb == 1)
		return 1;
	if (nb >= 2)
		result = ft_recursive_factorial(nb-1) * nb;
	return result; 
}

int main (void)
{
	int nb;

	nb = 3;
	printf("\nft_recursive_factorial: %i", ft_recursive_factorial(nb));
}
