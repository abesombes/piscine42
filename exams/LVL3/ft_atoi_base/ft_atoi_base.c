/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c         	                        :+:      :+:    :+:   */
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

int	index_base(char c, int base)
{
	char *base_lc="0123456789abcdef";
	char *base_uc="0123456789ABCDEF";
	int i;

	i = -1;
	while (++i < base)
	{
		if (base_lc[i] == c || base_uc[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int sign;
	int nbr;
	int i;

	sign = 1;
	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != '\r' && str[i] != '\f' && str[i] != '\n')
	{
		if (index_base(str[i], str_base) == -1)
			return (sign*nbr);
		else
			nbr = nbr * str_base + index_base(str[i], str_base);
		i++;
	}
	return (sign*nbr);
}

int main(void)
{
	char *s="   -7F";
	int base = 15;

	printf("\nhex value: %s | decimal value: %i", s, ft_atoi_base(s, base));
}
