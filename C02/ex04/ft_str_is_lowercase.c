/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c    	                        :+:      :+:    :+:   */
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


int 	ft_str_is_lowercase(char *str)
{	
	int i;
	int j;
	int is_lowercase;
	char *lowercase="abcdefghijklmnopqrstuvwxyz";
	
	is_lowercase=0;
	i = 0;
	while (str[i]!='\0')
	{
	j = -1;
	while (lowercase[++j])
	{
	if (lowercase[j] == str[i])
		is_lowercase++;
	printf("\ni: %i, lowercase[j]: %c, j: %i - is_lowercase: %i", i, lowercase[j], j, is_lowercase);	
	}
	i++;
	}
//	printf("\nSTRLEN: %i",ft_strlen(str));
	if (is_lowercase==ft_strlen(str))
	return (1);
	else
	return (0);
}

int	main(void)
{
	char *str;
	str = "ao.jofjd";

	printf("STR: %s", str);
	printf("\nIS LOWERCASE? %i\n", ft_str_is_lowercase(str));
}
