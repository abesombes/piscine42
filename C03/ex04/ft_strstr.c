/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
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
	int i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return i;
}

char	*ft_strstr(char *str, char *to_find)
{
	int i; 
	int j;
	char *substr;

	i = 0;
	
	while(str[i])
	{
		if (j != ft_strlen(to_find))
		{
		j = 0;
		substr = str;
		}
		while ((*str == to_find[j]) && (j <= ft_strlen(to_find)))
		{
			str++;
			j++;
		}
		str++;
	}
	if (j == ft_strlen(to_find))
	return substr;
	else
	return NULL;

}

int main (void)
{
	char string1[40]="bonjour robot, quel est ton nom?";
	char string2[10]="robotr";
	
	printf("\nstrstr: %s",strstr(string1, string2));
	printf("\nft_strstr: %s",ft_strstr(string1,string2));
}
