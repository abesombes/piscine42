/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/05 17:28:36 by abesombes        ###   ########.fr       */
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

bool ft_is_base_valid(char *c)
{
	int i;
	int j;
	int size;
	
	i = 0;
	size = 0;
	while (c[i++])
		size++;
	if (size <=1)
		return false;
	i = -1;
	while (c[++i])
	{
		if (c[i] == '-' || c[i] == '+')
			return false;
		j = i;
		while (c[j++])
		{
			if (c[i] == c[j])
			return false;
		}
	}
return true;
}

void ft_putnbr_base(int nbr, char *base)
{
	int sze;
	int i;

	sze = 0;
	i = -1;
	while (base[++i])
		sze++;

	if (ft_is_base_valid(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr > sze)
			ft_putnbr_base(nbr/sze, base);
		if (nbr % sze > 9)
			ft_putchar(base[nbr % sze]);
		else 
			ft_putchar(nbr % sze + '0');
	}
}

int main (void)
{
	char str[40]="0123";
	int nb;

	nb = -2536;
	ft_putnbr_base(nb, str);
}
