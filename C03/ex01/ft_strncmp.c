/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/09/03 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void 	ft_putchar(char c)
{
	write(1,&c,1);
}

int 	ft_strncmp(char *s1, char *s2, unsigned int n)
{	
	unsigned int i;
	i = 0;
	while (*s1 && *s2 && i < n)
	{
		if (*s1 != *s2)
		return (*s1 - *s2);
		*s1++;
		*s2++;
		i++;
	}

	return 0;
}

int		main(void)
{
	char str1[40]="BINGO";
	char str2[40]="BINGUDSSDDSDS";

	printf("\nFT_STRNCMP: %i", ft_strncmp(str1, str2, 6));
	printf("\nRESULTAT du vrai STRNCMP: %i\n", strncmp(str1, str2, 6));

}
