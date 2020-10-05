/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/25 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0) 
		n /= 2;
	return ((n == 1) ? 1 : 0);
}

int is__power_of_2(unsigned int n)
{
	unsigned int i;

	i = 1;
	if (n == 1)
		return 1;
	while (i * 2 < n)
		i *= 2;
	if (i * 2 == n)
		return 1;
	else
		return 0;
}

int main(void)
{
	unsigned int nbr;

	nbr = 0;
	while (nbr < 257)
	{
		printf("\n%i is power_of_2: %i", nbr, is_power_of_2(nbr));
	nbr++;
	}
}
