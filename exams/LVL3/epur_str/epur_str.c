/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c         	                        :+:      :+:    :+:   */
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

int		ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

void	epurstr(char *s)
{
	int len = ft_strlen(s);

	while (len && ft_isblank(s[len - 1]))
		--len;
	while (len && ft_isblank(*s) && *s++)
		--len;
	while (len--)
	{
		if (!ft_isblank(*s) || (*(s + 1) && !ft_isblank(*(s + 1))))
			write(1, s, 1);
		s++;
	}
}

int is_spacetab(char c)
{

	if ((c == ' ') || (c == '\t'))
		return (1);
	else
		return (0);
}

void epur_str(char *str)
{
	int i;
	int sentence_begin;

	sentence_begin = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_spacetab(str[i]))
			i++;
		if (i < ft_strlen(str) && is_spacetab(str[i-1]) && sentence_begin != 1)
			write(1, " ", 1);
		while (str[i] && !is_spacetab(str[i]))
		{
			write(1, &(str[i]), 1);
			i++;
		}
		sentence_begin = 0;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		epur_str(av[1]);
	}
	write(1, "\n" ,1);
}
