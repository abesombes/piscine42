/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c        	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/03 17:28:36 by abesombes        ###   ########.fr       */
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

int is_spacetab(char c)
{
	if ((c == ' ') || (c > 9 && c < 13))
		return 1;
	else
		return 0;
}

void expand_str(char *str)
{
	int i;
	int sbegin;

	i = 0;
	sbegin = 1;
	while (str[i])
	{
		while (str[i] && is_spacetab(str[i]))
		{
//			printf("\nsbegin: %i | strlen: %i | i = %i", sbegin, ft_strlen(str), i);
			i++;
		}
		if (sbegin != 1 && i <= ft_strlen(str) - 1)
			write(1, "   ", 3);

		while (str[i] && !is_spacetab(str[i]))
		{
			write(1, &(str[i++]), 1);
			sbegin = 0;
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
}
