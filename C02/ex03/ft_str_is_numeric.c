/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c       	                        :+:      :+:    :+:   */
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


int 	ft_str_is_numeric(char *str)
{	
	int i;
	int j;
	int is_numeric;
	char *digits="0123456789";
	
	is_numeric=0;
	i = 0;
	while (str[i]!='\0')
	{
	j = -1;
	while (digits[++j])
	{
	if (digits[j] == str[i])
		is_numeric++;
	printf("\ni: %i, digits[j]: %c, j: %i - is_numeric: %i", i, digits[j], j, is_numeric);	
	}
	i++;
	}
//	printf("\nSTRLEN: %i",ft_strlen(str));
	if (is_numeric==ft_strlen(str))
	return (1);
	else
	return (0);
}

int		main(void)
{
	char *str;
	str = "12.3";

	printf("STR: %s", str);
	printf("\nIS NUMERIC? %i\n", ft_str_is_numeric(str));
}
