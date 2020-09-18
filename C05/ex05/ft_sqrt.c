/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
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

int ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
		return -1;
	if (nb == 0)
		return 0;
	while (i * i < nb)
		i++;
	if (i * i  == nb)
		return i;
	return 0;
}

int main (void)
{
	int nb;

	nb = 283787717;
	printf("\nft_sqrt(%i): %i", nb, ft_sqrt(nb));
}

