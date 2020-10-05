/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c 	        	                        :+:      :+:    :+:   */
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

void ft_putnbr(int nbr)
{
	int modulo;

	if (nbr > 9)
		ft_putnbr(nbr/10);
	modulo = nbr % 10 + '0';
	write(1, &modulo, 1);
}

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

int pgcd(int nbr1, int nbr2)
{
	int i;
	int pgcd;

	pgcd = 0;
	i = 1;
	while (i < nbr1 || i < nbr2)
	{
		if ((nbr1 % i == 0) && (nbr2 % i == 0))
			pgcd = i;
		i++;
	}
	return (pgcd);
}

int main(int ac, char **av)
{
	int int1;
	int int2;

	if (ac == 3)
	{
		int1 = ft_atoi(av[1]);
		int2 = ft_atoi(av[2]);
		ft_putnbr(pgcd(int1, int2));
	}
	write(1, "\n", 1);

}
