/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/03 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

int main (void)
{
	char string1[50]="test 1 2 3 ";

	printf("\nstrlen: %li",strlen(string1));
	printf("\nft_strlen: %i",ft_strlen(string1));
}
