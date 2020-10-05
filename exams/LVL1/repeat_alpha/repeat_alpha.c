/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/24 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int main(int ac, char **av)
{
	int i;
	int count;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{ 
				count = 0;
				while (count++ <= av[1][i] - 'a')
					write(1, &(av[1][i]), 1);
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{ 
				count = 0;
				while (count++ <= av[1][i] - 'A')
					write(1, &(av[1][i]), 1);
			}
			else
			{
				write(1, &(av[1][i]), 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
