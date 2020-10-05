/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/29 17:28:36 by abesombes        ###   ########.fr       */
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

unsigned char	swap_bits(unsigned char octet)
{
	octet = (((octet & 240) >> 4) | ((octet & 15) << 4));
	return (octet);
}

int main(void)
{
	unsigned char s;

	s = '5';
	printf("\ninitial s: %c - swap_bits: %c", s, swap_bits(s));
}
