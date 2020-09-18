/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 20:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/11 20:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void 	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_is_str1_greater_than_str2(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i])
	{
	if (str1[i] > str2[i])
		return(1);
	else if (str1[i] < str2[i])
		return(0);
	i++;
	}
return (0);
}

int 	main (int argc, char **argv)
{
	int i;
	int index[argc];
	int tmp;

	i = -1;
	while(++i < argc)
		index[i] = i;
	i = -1;
	while (++i < argc - 1)
	{
		if (ft_is_str1_greater_than_str2(argv[index[i]],argv[index[i+1]]))
		{
			tmp = index[i];
			index[i] = index[i+1];
			index[i+1] = tmp;
			i = 0;
		}
	}
	i = 0;
	while (++i < argc)
		ft_putstr(argv[index[i]]);
}
