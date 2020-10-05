/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/29 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_union(char *str1, char *str2)
{
	int i;
	int j;

	i = 1;
	write(1, &(str1[0]), 1);
		while (str1[i] != '\0')
		{
			j = 0;
			while (j < i && str1[i] != str1[j])
				j++;
			if (j == i)
				write(1, &(str1[i]),1);
			i++;
		}
		i = 0;
		while (str2[i] != '\0')
		{
			j = 0;
			while (j < ft_strlen(str1) && str2[i] != str1[j])
				j++;
			if (j == ft_strlen(str1))
			{
				j = 0;
				while (str2[i] != str2[j])
					j++;
				if (j == i)
					write(1, &(str2[i]),1);
			}
			i++;
		}
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n" ,1);
}
