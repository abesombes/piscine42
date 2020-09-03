/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
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
#include <bsd/string.h>

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

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{

	unsigned int i;
	char *str;
	unsigned int size_dest;

	str = dest;
	size_dest = ft_strlen(dest);
	i = 0;
	if (!src)
		return (size_dest);
	while(*dest)
		dest++;
	while(*src && i < size - size_dest)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest='\0';
	printf("\nDESTfinale : %s|", str);
	return ft_strlen(str);
}

int main (void)
{
	char string1[50]="bonjour robot, ";
	char string2[40]="quel est ton nom?";	
//	printf("\nstrlcat: %li",strlcat(string1,string2,20));
	printf("\nft_strlcat: %i",ft_strlcat(string1,string2,20));
}
