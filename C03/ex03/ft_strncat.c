/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/03 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *str;
	unsigned int i;

	i = 0;
	str=dest;
	while (*dest)
		dest++;

	while (*src && i < nb)
		{
		*dest=*src;
		dest++;
		src++;
		i++;
		}
	
	*dest = '\0';	
	return str;

}

int main (void)
{
	char string1[40]="hello";
	char string2[18]=" mon petit bichon";
	char string3[40]="hello";
	char string4[18]=" mon petit bichon";
	
	printf("\nstrncat: %s",strncat(string1, string2, 12));
	printf("\nft_strncat: %s",ft_strncat(string3, string4, 12));
}
