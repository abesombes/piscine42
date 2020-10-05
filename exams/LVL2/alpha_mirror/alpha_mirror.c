/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/27 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;
	while (str[i])
		i++;
	return(i);
}

char *alpha_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 219 - str[i];
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 155 - str[i];
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	char *res;

	(void)ac;
	if (ac == 2)
	{
		res =  alpha_mirror(av[1]);
		write(1, res, ft_strlen(res));
	}
	write(1, "\n", 1);
}
