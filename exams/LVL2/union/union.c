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

int ft_unseen_bef(char *s, int pos, char c)
{
	int j;

	j = 0;
	while (j < pos)
	{
		if (s[j] == c)
			return 0;
		j++;
	}
	return 1;
}

void ft_union(char *str1, char *str2)
{
	int i;

	i = 1;
	write(1, &(str1[0]), 1);
	while (str1[i] != '\0')
	{
		if (ft_unseen_bef(str1, i, str1[i]))
			write(1, &(str1[i]),1);
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		if (ft_unseen_bef(str1, ft_strlen(str1), str2[i])
			&& ft_unseen_bef(str2, i, str2[i]))
				write(1, &(str2[i]),1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n" ,1);
}
