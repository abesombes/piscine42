/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c		                                :+:      :+:    :+:   */
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

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				if (av[1][i] + 1 <= 122)
					av[1][i] += 1;
				else 
					av[1][i] -= 25;
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				if (av[1][i] + 1 <= 90)
					av[1][i] += 1;
				else
				 	av[1][i] -= 25;
			}
			write(1, &(av[1][i]), 1);
			i++;
		}
	}
	write(1,"\n", 1);
}
