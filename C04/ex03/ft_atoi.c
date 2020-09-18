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

	sign = 1;
	nb = 0;
	while (*str)
	{
		while (ft_is_whitespace(*str))
			str++;
		while (ft_is_plusminus(*str) != 0)
		{
			sign = sign * ft_is_plusminus(*str);
			str++;
		}
		while (ft_is_digit(*str))
		{
			nb = *str - 48 + nb * 10;
			str++;
		}
	return (nb*sign);
	str++;
	}
return (nb*sign);
}

int main (void)
{
	char str[40]="  +--23 ---+--+1+234ab567";

	printf("\nft_atoi: %i",ft_atoi(str));
}
