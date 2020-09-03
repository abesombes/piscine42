/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/25 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void 	ft_putchar(char c)
{
	write(1,&c,1);
}

unsigned int ft_strlen(char *str)
{
	unsigned int i;

	while (str[i]!='\0')
		i++;

	return (i);
}


char	*ft_strncpy(char *dest, char *src, unsigned int n)
{	
	unsigned int i;
	
	i = 0;
	while ((i<n) && src[i])
	{
	if (src[i]!='\0')
		dest[i] = src[i];
	i++;
	}
	
	if (ft_strlen(src)<n)
	{
		while (i<n)
		dest[i++] ='\0';
	}
	
	return dest;
}

int		main(void)
{
	char *src;
	char dest[15];
	src = "Hello World";

	printf("SRC: %s", src);
	printf("\nDEST: %s", ft_strncpy(dest, src, 14));
	printf("\nRESULTAT du vrai STRCPY: %s\n", strncpy(dest, src, 14));

}
