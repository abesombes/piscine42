*/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
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
#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char* str, char *base_to);

int 	ft_strlen(char *str)
{
	int count;
	count = 0;
	while (str[count])
		count++;
	return (count);
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

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int sign;
	int nbr_dec;
	char* rebased;

	sign = 1;
	if ((!ft_check_base(base_from)) || (!ft_check_base(base_to)))
		return (NULL);
	nbr_dec = 0;
	while (*nbr)
	{
		while (ft_is_whitespace(*nbr))
			nbr++;
		while (ft_is_plusminus(*nbr) != 0)
		{
			sign = sign * ft_is_plusminus(*nbr);
			nbr++;
		}
		while ((!ft_is_whitespace(*nbr)) && (!ft_is_plusminus(*nbr)))
		{
			nbr_dec = ft_find_index(*nbr, base_from) + nbr_dec * ft_find_index(' ', base_from);
			nbr++;
		}
//	printf("\nnbr_dec: %i", nbr_dec*sign);
//	printf("\nbase_to: %s", base_to);
	rebased = (char *)malloc(sizeof(char)*1000);
//	printf("\nrebased: $%s$", rebased);
	return (ft_putnbr_base(nbr_dec*sign, rebased, base_to));
	nbr++;
	}
return (base_to);
}

int main (void)
{
	char *str = "  +-----+--+eioopp+234ab567";
	char *base_from = "poneyvif";
	char *base_to = "0123456789abcdef";
 
	printf("\nft_convert_base: %s",ft_convert_base(str, base_from, base_to));
}
