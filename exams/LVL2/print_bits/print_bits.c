/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/29 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int power_of_2(int power)
{
	int i;
	int res;

	res = 1;
	i = power;
	while (i > 0)
	{
		res = res * 2;
		i--;
	}
	return res;
}


void	print_bits2(unsigned char octet)
{
	int	i = 256;
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
}

void	print_bits(unsigned char octet)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (octet >= power_of_2(i))
		{
			write(1, "1", 1);
			octet = octet - power_of_2(i);
		}
		else
			write(1, "0", 1);
		i--;
	}
}

int main(void)
{
	unsigned char nbr;

	nbr = 245;
	print_bits(nbr);
}
