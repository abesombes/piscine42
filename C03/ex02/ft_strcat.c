/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
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

int ft_strlen(char *str)
{
	int j;

	while (*str)
	{
		j++;
		str++;
	}
	return (j);
}

char	*ft_strcat(char *dest, char *src)
{
	char *str;

	str=dest;
	while (*dest)
		dest++;

	while(*src)
	{
	*dest=*src;
	dest++;
	src++;
	}
	
	*dest = '\0';	
	return str;

}

int main (void)
{
	char string1[40]="hello";
	char string2[40]=" mon petit bichon";
	char string3[40]="hello";
	char string4[40]=" mon petit bichon";
	
	printf("\nstrcat: %s",strcat(string1, string2));
	printf("\nft_strcat: %s",ft_strcat(string3,string4));
}
