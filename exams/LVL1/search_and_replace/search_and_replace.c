/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/24 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int count;
	int i;

	count = 0;
	if (ac == 4)
	{
		i = 0;
		while(av[1][i])
		{
			if (ft_strlen(av[2]) == 1 && ft_strlen(av[3]) == 1)
			{
				if (av[1][i] == av[2][0])
				{
					count++;
					av[1][i] = av[3][0];
				}
				write(1, &(av[1][i]), 1);
			}
				av[1]++;
		}
		if (count == 0)
			write(1, &av[1], ft_strlen(av[1])); 
	}
	write(1,"\n",1);
}
