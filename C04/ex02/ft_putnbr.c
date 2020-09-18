/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/04 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

int ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	return i;
}

void ft_putnbr(int nb)
{
	if (nb < 0)
	{
	ft_putchar('-');
	nb = -nb;
	}
	if (nb == -2147483648)
		write(1, "2147483648", 10);

	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int main (void)
{
	int nb1;

	nb1 = -2147483648;
	ft_putnbr(nb1);
}
