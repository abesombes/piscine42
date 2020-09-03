/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/27 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char 	*ft_strlowcase(char *str)
{	
	int i;
	int j;
	char *uppercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	i = 0;
	while (str[i]!='\0')
	{
	j = -1;
	while (uppercase[++j])
		{
		if (uppercase[j] == str[i])
			str[i] = str[i] + 32;
		}
	i++;
	}
	return(str);
}

int 	main(void)
{
	char str[15] = "HELLO0WORLD";
	
	printf("STR: %s", str);
	printf("\nSTR LOWERCASE: %s\n", ft_strlowcase(str));
}
