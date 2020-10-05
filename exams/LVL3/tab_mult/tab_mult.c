/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/04 17:28:36 by abesombes        ###   ########.fr       */
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

void tab_mult(unsigned int a)
{
	unsigned int i;
	char c;

	i = 1;
	while (i <= 9)
	{
		write(1, "\n", 1);
		c = i + '0';
		write(1, &c, 1);
		write(1, " x ", 3);
		ft_putnbr(a);
		write(1, " = ", 3);
		ft_putnbr(i*a);
		i++;
	}
}

int main(int ac, char **av)
{
	int int1;

	if (ac == 2)
	{
		int1 = ft_atoi(av[1]);
		tab_mult(int1);
	}
	write(1, "\n", 1);

}
