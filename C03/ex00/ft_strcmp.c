/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/06/03 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void 	ft_putchar(char c)
{
	write(1,&c,1);
}

int 	ft_strcmp(char *s1, char *s2)
{	
	int i;
	int j;
	int diff;
	
	i = 0;
	j = 0;
	while ((s1[i]!='\0')&&(s2[i]!='\0'))
	{
		if (s1[i] == s2[i])
		j++;
		else 
		diff = s1[i] - s2[i];
		i++;
	}
	if (i == j)
	return 0;
	else 
	return diff;
}

int		main(void)
{
	char str1[]="BINGO";
	char str2[]="BINGUDSSDDSDS";

	printf("\nSTR1: %s", str1);
	printf("\nSTR2: %s", str2);
	printf("\nComparaison des STR1 et STR2: %i", ft_strcmp(str1, str2));
	printf("\nRESULTAT du vrai STRCMP: %i\n", strcmp(str1, str2));

}
