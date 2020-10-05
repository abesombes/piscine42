/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c	            	                        :+:      :+:    :+:   */
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

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_is_space(char c)
{

	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && !ft_is_space(str[i]) && ft_isdigit(str[i]))
	{
		printf("\nres: %i", res);
		res = str[i] - 48 + 10 * res;
		printf("\nres: %i", res);
		i++;
	}
	return (res*sign);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("\nstr: %s | Atoi: %i | ft_atoi: %i\n", av[1], atoi(av[1]), ft_atoi(av[1]));
	}
	write(1, "\n", 1);
}
