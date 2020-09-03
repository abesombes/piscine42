/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c         	                        :+:      :+:    :+:   */
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

char	*ft_strcpy(char *dest, char *src)
{	
	int i;
	
	i = 0;
	while (src[i]!='\0')
	{
	dest[i] = src[i];
	i++;
	}
	dest[i]='\0';
	
	return dest;
}

int		main(void)
{
	char src[]="BINGO";
	char dest[]="WAITING FOR INPUT";

	printf("SRC: %s", src);
	printf("\nDEST: %s", ft_strcpy(dest, src));
	printf("\nRESULTAT du vrai STRCPY: %s\n", strcpy(dest, src));

}
