/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/24 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i;
	int size;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		size = i - 1;
		while (size >= 0)
		{
//			printf("\nsize: %i, av[1][size]: %c", size, av[1][size]);
			write(1, &(av[1][size]), 1);
			size--;
		}
	}
	write(1,"\n", 1);
}
