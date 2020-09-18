/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
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
#include <stdbool.h>

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

bool ft_is_whitespace(char c)
{
	if ((c == ' ') || (c == '\f') || (c == '\n') || (c == '\r') || (c == '\t') || (c =='\v'))
		return true;
	else
		return false;
}

int ft_is_plusminus(char c)
{
	if (c == '-') 
	return -1;
	if (c == '+')	
	return 1;
	return 0;
}

bool ft_is_digit(char c)
{
	if (c - 48 >= 0 && c - 48 < 10)
	return(true);
	else
	return(false);
}


int ft_atoi(char *str)
{
	int sign;
	int nb;
	int endofwhitespace;
	int endofplusminus;

	sign = 1;
	endofwhitespace=0;
	endofplusminus=0;
	nb = 0;
	while (*str)
	{
	if (ft_is_whitespace(*str) && endofwhitespace == 0 )
		nb = nb;
	else if (ft_is_plusminus(*str) != 0 && endofplusminus == 0)
		{
		sign = sign * ft_is_plusminus(*str);
		endofwhitespace = 1;
		}
	else if (ft_is_digit(*str))
		{
		nb = *str - 48 + nb * 10;
		endofplusminus = 1;
		}
	else
	return (nb*sign);
	str++;
	}
return (nb*sign);
}

int main (void)
{
	char str[40]="  +---+--+ 1+234ab567";
//	char str2[20]="5";
	printf("\nft_atoi: %i",ft_atoi(str));
//	printf("\nft_is_digit: %d", ft_is_digit(*str2)); 
}
