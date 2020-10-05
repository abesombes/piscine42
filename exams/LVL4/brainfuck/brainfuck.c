/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c         	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/04 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int find_sister_bracket(char *str, int currentpos)
{
	char curr_bracket;
	char bracket_to_find;
	int count_inner_bracket;

	count_inner_bracket = 0;
	curr_bracket = str[currentpos];
	bracket_to_find = ((curr_bracket == '[') ?  ']' : '[');
	(curr_bracket == '[') ? currentpos++ : currentpos--;
	while (count_inner_bracket >= 0)
	{
		while (str[currentpos] != bracket_to_find)
		{
			if (str[currentpos] == curr_bracket)
				count_inner_bracket++;
			(curr_bracket == '[')? currentpos++: currentpos--;
		}
			(curr_bracket == '[')? currentpos++: currentpos--;
		count_inner_bracket--;
	}
	return (currentpos);
}

void 	brainfuck(char *str)
{
	int i;
	char s[2048];
	int ptr;

	i = -1;
	while (++i < 2048)
		s[i] = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			s[ptr]++;
		if (str[i] == '-')
			s[ptr]--;
		if (str[i] == '>')
			ptr++;
		if (str[i] == '<')
			ptr--;
		if (str[i] == '.')
			write(1, &(s[ptr]), 1);
		if ((str[i] == '[' && s[ptr] == 0) || (str[i] == ']' && s[ptr] != 0))
			i = find_sister_bracket(str, i);
		i++;
	}
}

int 	main(int ac, char **av)
{
	if (ac == 2)
	{
		brainfuck(av[1]);
	}
}
