/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/06 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

void ft_putchar (char c)
{
	write(1, &c, 1);
}

int ft_fibonacci(int index)
{
	int result;

	result = 0;
	if (index < 0)
		return -1;
	if (index == 0)
		return 0;
	else if (index == 1)
		return 1;
	else 
	if (index >=2)
	{
		result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
//		printf("\nF(%i): %i", index , result);
	}
	return result; 
}

int main (void)
{
	int index;

	index = 3;
	printf("\nft_fibonacci(%i): %i", index, ft_fibonacci(index));
}

