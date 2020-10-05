/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c 	        	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/03 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
	int i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb*sign);
}

void print_hex(int nbr)
{
	char *base = "0123456789abcdef";
	char c;

	if (nbr > 15)
		print_hex(nbr / 16);
//	printf("\nnbr modulo 16: %i | base[]: %c", nbr % 16, base[nbr % 16]);
	c = base[nbr % 16];
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
}
