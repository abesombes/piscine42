/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c	    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/28 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	
	i = 0;
	while((i<size-1) && (src[i]))
	{
		dest[i]=src[i];
		i++;
	}
	dest[i]='\0';
	return (i+1);	
}

int 	main(void)
{
	char str[12] = "hello world";
	char dest[15] = "";
	char str2[12] = "hello world";
	char dest2[15]="";

	printf("STR: %s", str);
	printf("\nsize: %i - dest : %s", ft_strlcpy(dest, str, 7), dest);
	printf("\nsize: %i - vstrlcpy : %s\n", ft_strlcpy(dest2, str2, 7), dest2);
}
