/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/25 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(unsigned char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned char *ft_strdup(unsigned char *src)
{
	int i;
	unsigned char *dup;

	i = 0;
	dup = (unsigned char *)malloc(ft_strlen(src)+1);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int *ft_convert_to_bits(unsigned char s)
{
	int i;
	int nbr;
	int *byte;

	nbr = s + 0;
	i = 0;
	while (i < 8)
	{
		while (nbr > 1)
		{
			byte[7 - i] = nbr % 2;
			nbr = nbr / 2;
			i++;
		}
	}
	return (byte);
}

unsigned char	reverse_bits(unsigned char octet)
{

	int i;
	unsigned char *dup_octet;


	dup_octet = ft_strdup(octet);
	i = 0;
	while (i < 4)
	{
		octet[i] = octet[8 - i] 
		i++;
	}
	i = 4;
	while (i < 8)
	{
		octet[i] = dup_octet[8 - i];
		i++;
	}
	return (octet);
}

int main(int ac, char **av)
{	
	int byte[8];
	unsigned char s;

	s = 'z';
	byte = ft_convert_to_byte(s);
	printf("\nbyte: %s", byte);
//	if (ac == 2)
//	{
//		printf("\ninitial byte: %c | reverse_bits: %c", s, reverse_bits(s));
//	}
}
