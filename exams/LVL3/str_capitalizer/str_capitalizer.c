/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/02 17:28:36 by abesombes        ###   ########.fr       */
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

int is_alphanumeric(char c)
{

	//if ((c >= 'a' && c <= 'z') || (c >='0' && c <= '9') || (c >= 'A' && c <= 'Z') || c == '\'')
	if ((c == ' ') || (c == '\t'))
		return (0);
	else
		return (1);
}

void str_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		while (str[i] && !is_alphanumeric(str[i]))
		{
			write(1, &(str[i]), 1);
			i++;
		}
		if (str[i] && (str[i] >= 'a') && (str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
			write(1, &(str[i]), 1);
			i++;
		}
		while (str[i] && is_alphanumeric(str[i]))
		{
			write(1, &(str[i]), 1);
			i++;
		}
	}
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i <= ac)
		{
			str_capitalizer(av[i]);
			write(1, "\n" ,1);
			printf("\ni: %i", i);
			i++;
		}
	}
}
