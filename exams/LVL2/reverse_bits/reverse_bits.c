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

int *ft_convert_to_bits(unsigned char s)
{
	int i;
	int nbr;
	int *byte;

	byte = (int*)malloc(sizeof(int)*8);
	nbr = s + 0;
	i = 0;
	while (i < 8)
	{
		while (nbr >= 0 && i < 8)
		{
			byte[7 - i] = nbr % 2;
			nbr = nbr / 2;
			i++;
		}
		i++;
	}
	return (byte);
}

unsigned char	reverse_bits(unsigned char octet)
{
	int i;
	int *str_octet;
	int *dup_octet;

	str_octet = (int*)malloc(sizeof(int)*8);
	dup_octet = (int*)malloc(sizeof(int)*8);
	str_octet = ft_convert_to_bits(octet);
	printf("\nstr_octet: %i%i%i%i%i%i%i%i", str_octet[0], str_octet[1], str_octet[2], str_octet[3], str_octet[4], str_octet[5], str_octet[6], str_octet[7]);
	i = 0;
	while (i < 8)
	{
		dup_octet[i] = str_octet[i];
		i++;
	}
	printf("\ndup_octet: %i%i%i%i%i%i%i%i", dup_octet[0], dup_octet[1], dup_octet[2], dup_octet[3], dup_octet[4], dup_octet[5], dup_octet[6], dup_octet[7]);
	i = 0;
	while (i < 4)
	{
		str_octet[i] = str_octet[7 - i];
		i++;
	}
	i = 4;
	while (i < 8)
	{
		str_octet[i] = dup_octet[7 - i];
		i++;
	}
	printf("\noctet: %i%i%i%i%i%i%i%i", str_octet[0], str_octet[1], str_octet[2], str_octet[3], str_octet[4], str_octet[5], str_octet[6], str_octet[7]);
	octet = 0;
	i = 0;
	while (i <= 7)
	{	
		octet = str_octet[i++] + octet * 2;
		printf("\noctet: %i %c", octet, octet);
	}
	return (octet);
}

int main(void)
{
//	int *octet;
	unsigned char s;

	s = '&';
	printf("\ninitial s: %c - rev_bits: %c", s, reverse_bits(s));
//	if (ac == 2)
//	{
//		printf("\ninitial byte: %c | reverse_bits: %c", s, reverse_bits(s));
//	}
}
