/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/23 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
	if (c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	int i;
	int from;
	int until;

	if (argc == 2)
	{
		i = 0;
		from = 0;
		while (argv[1][i] && ft_is_space_tab(argv[1][i]) == 1)
		{
			from = i + 1;
			i++;
		}
		printf("\nfrom: %i", from);
		i++;
		while (argv[1][i] && i < ft_strlen(argv[1]) && ft_is_space_tab(argv[1][i]) == 0)
		{
			until = i + 1;
			i++;
		}
		printf("\nuntil: %i", until);
		write(1, "$", 1);
		while (from < until)
			write(1, &(argv[1][from++]), 1);
		write(1, "$", 1);
	}
	write(1,"\n",1);
	return (0);
}
