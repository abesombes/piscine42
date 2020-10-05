/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c        	                        :+:      :+:    :+:   */
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

char *rev_str(char *s)
{
	int i;
	char c;
	int size;

	size = ft_strlen(s);
	i = 0;
	while (s[i] && i < size / 2)
	{
		c = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = c;
		i++;
	}
	return (s);
}

int is_spacetab(char c)
{
	if ((c == ' ') || (c > 9 && c < 13))
		return 1;
	else
		return 0;
}

void rstr_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (is_spacetab(str[i + 1]) || str[i + 1] == '\0'))
			str[i] -= 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z') && (!is_spacetab(str[i + 1]) && str[i + 1] != '\0'))
			str[i] += 32;
		write(1, &(str[i]), 1);
		i++;
	}

}

void rstr_capitalizer2(char *str)
{
	int i;

	i = -1;
	str = rev_str(str);
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
	i = 0;
	while (str[i])
	{
		while (str[i] && is_spacetab(str[i]))
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i++] -= 32;
		while (str[i] && !is_spacetab(str[i]))
			i++;
	}
	str = rev_str(str);
	i = 0;
	while (str[i])
		write(1, &(str[i++]), 1);
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac >= 2)
	{
		while (i <= ac - 1)
		{
			rstr_capitalizer(av[i++]);
			write(1, "\n", 1);
		}
	}
	write(1, "\n", 1);
}
