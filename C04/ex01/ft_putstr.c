/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/04 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

int ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	return i;
}

void ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int main (void)
{
	char string1[50]="test 1 2 3 ";

//	printf("\nstrlen: %li",strlen(string1));
//	printf("ft_putstr: ");
	ft_putstr(string1);
}
