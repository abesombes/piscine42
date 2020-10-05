/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/01 17:28:36 by abesombes        ###   ########.fr       */
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

void ft_hidenp(char *s1, char *s2)
{
	int i;
	int j;
	int  not_found;

	i = 0;
	j = 0;
	not_found = 0;
	if (ft_strlen(s1)==0)
		write(1, "1", 1);
	else
	{
		while (s1[i] && not_found == 0)
		{
			while (s2[j] && s2[j++] != s1[i]);
			if (j == ft_strlen(s2) && i <= ft_strlen(s1))
			{
				not_found = 1;
				write(1, "0", 1);
			}
			i++;
		}
		if (not_found == 0)
			write(1, "1", 1);
	}
}

void	hidenp(char *s1, char *s2)
{
	while (*s2)
		if (*s1 == *s2++)
			s1++;
	(*s1 == '\0') ? write(1, "1", 1) : write(1, "0", 1);
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_hidenp(av[1], av[2]);
	write(1, "\n" ,1);
}
