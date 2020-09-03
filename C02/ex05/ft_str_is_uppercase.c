/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/26 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void 	ft_putchar(char c)
{
	write(1,&c,1);
}

int 	ft_strlen(char *str)
{
	int i;

	while (str[i]!='\0')
		i++;

	return (i);
}


int 	ft_str_is_uppercase(char *str)
{	
	int i;
	int j;
	int is_uppercase;
	char *uppercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	is_uppercase=0;
	i = 0;
	while (str[i]!='\0')
	{
	j = -1;
	while (uppercase[++j])
	{
	if (uppercase[j] == str[i])
		is_uppercase++;
//	printf("\ni: %i, uppercase[j]: %c, j: %i - is_uppercase: %i", i, uppercase[j], j, is_uppercase);	
	}
	i++;
	}
//	printf("\nSTRLEN: %i",ft_strlen(str));
	if (is_uppercase==ft_strlen(str))
	return (1);
	else
	return (0);
}

int	main(void)
{
	char *str;
	str = "";

	printf("STR: %s", str);
	printf("\nIS UPPERCASE? %i\n", ft_str_is_uppercase(str));
}
