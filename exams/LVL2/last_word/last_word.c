/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/28 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return(i);
}

int ft_is_space_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

void ft_concat(char *str, char d)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	str[i] = d;
}

int main(int ac, char **av)
{
	int i;
	int count;
	char *last_word;

	count = 0;
	if (ac == 2)
	{
		i = ft_strlen(av[1]) - 1;
		while (av[1][i] && ft_is_space_tab(av[1][i]))
			i--;
		while (av[1][i] && !ft_is_space_tab(av[1][i--]))
			count++;
		last_word=(char *)malloc(count + 1);
		i = ft_strlen(av[1]) - 1;
		while (av[1][i] && ft_is_space_tab(av[1][i]))
			i--;
		while (av[1][i] && !ft_is_space_tab(av[1][i--]))
			ft_concat(last_word, av[1][i+1]);
		count = ft_strlen(last_word) - 1;
		while (last_word[count])
			write(1, &(last_word[count--]), 1);
	}
	write(1, "\n", 1);
}
