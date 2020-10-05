/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/02 17:28:36 by abesombes        ###   ########.fr       */
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

int sqrt_rounded(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

int add_prime_sum(int nbr)
{
	int i;
	int j;
	int sum;
	int is_not_prime;

	i = 2;
	sum = 0;
	while (i <= nbr)
	{
		is_not_prime = 0;
		j = 2;
		while (j <= sqrt_rounded(i))
		{
			if (i % j == 0 && i != 2)
				is_not_prime = 1;
			j++;
		}
		if (is_not_prime == 0)
			sum += i;
		i++;
	}
	return (sum);
}

int main(int ac, char **av)
{
	int somme;

	if (ac == 2 && ft_atoi(av[1]) >= 0)
	{
		somme = add_prime_sum(ft_atoi(av[1]));
		ft_putnbr(somme);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);

}
