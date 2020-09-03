/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c         	                        :+:      :+:    :+:   */
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

int ft_strlen(char *str)
{
	int i;

	while (str[i]!='\0')
		i++;

	return (i);
}


int ft_str_is_alpha(char *str)
{	
	int i;
	int j;
	int is_alpha;
	char *alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	is_alpha=0;
	i = 0;
	while (str[i]!='\0')
	{
	j = -1;
	while (alphabet[++j])
	{
	if (alphabet[j] == str[i])
		is_alpha++;
//	printf("\ni: %i, alphabet[j]: %c, j: %i - is_alpha: %i", i, alphabet[j], j, is_alpha);	
	}
	i++;
	}
//	printf("\nSTRLEN: %i",ft_strlen(str));
	if (is_alpha==ft_strlen(str))
	return (1);
	else
	return (0);
}

int		main(void)
{
	char *str;
	str = "";

	printf("STR: %s", str);
	printf("\nIS ALPHA? %i\n", ft_str_is_alpha(str));
}
