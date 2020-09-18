/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/16 17:28:36 by abesombes        ###   ########.fr       */
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

int ft_find_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
	{
	i++;
	}
	return (i);
}

bool ft_check_base(char *base)
{
	int i;
	int j;
	int basesize;

	i = -1;
	basesize = 0;
	while (base[++i])
		basesize++;
	i = -1;
	while (base[++i])
	{
		if ((ft_is_plusminus(base[i]) != 0) || (ft_is_whitespace(base[i])))
			return (false);
		j = i;
		while (++j < basesize)
		{
			if (base[j] == base[i])
				return (false);
		}
	}
	if (i <= 1)
		return (false);
	return (true);
}

int ft_atoi_base(char *str, char *base)
{
	int sign;
	int nb;

	sign = 1;
	nb = 0;
	if (!ft_check_base(base))
		return (0);
	while (*str)
	{
		while (ft_is_whitespace(*str))
			str++;
		while (ft_is_plusminus(*str) != 0)
		{
			sign = sign * ft_is_plusminus(*str);
			str++;
		}
		while ((!ft_is_whitespace(*str)) && (!ft_is_plusminus(*str)))
		{
			nb = ft_find_index(*str, base) + nb * ft_find_index(' ', base);
			str++;
		}
	return (nb*sign);
	str++;
	}
return (nb*sign);
}

int main (void)
{
	char *str = "  +-----+--+eioopp+234ab567";
	char *base = "pon-eyvif";
 
	printf("\nft_atoi_base: %i",ft_atoi_base(str, base));
}
