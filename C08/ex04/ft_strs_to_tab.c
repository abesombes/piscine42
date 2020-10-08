/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/23 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_stock_str.h"

#include <stdlib.h>
#include <stdio.h>

int 			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char 			*ft_strdup(char *src)
{
	int 		i;
	char 		*dup;
	if (!(dup = malloc(sizeof(char)*(ft_strlen(src) + 1))))
		return NULL;
	i = -1;
	while (src[++i])
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}


struct s_stock_str 	*ft_strs_to_tab(int ac, char **av)
{
	int 		i;
	int 		sze;
	t_stock_str	*res;

	if (!(res=(t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = 0;
	sze = 0;
	while (i < ac)
	{
		sze = ft_strlen(av[i]);
		if (!(res[i].str=(char *)malloc(sizeof(char) * (sze + 1))))
			return (NULL);
		if (!(res[i].copy=(char *)malloc(sizeof(char) * (sze + 1))))
			return (NULL);
		res[i].size = sze;
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
	i++;
	}
	res[i].str = 0;
	res[i].copy = 0;
	res[i].size = 0;
	return (res);
}

//int					main(int argc, char **argv)
//{
//	int					index;
//	struct s_stock_str	*structs;
//
//	structs = ft_strs_to_tab(argc, argv);
//	index = 0;
//	while (index < argc)
//	{
//		printf("%d\n", index);
//		printf("\t| original : $%s$ @ %p\n", structs[index].str, structs[index].str);
//		printf("\t|   copied : $%s$ @ %p\n", structs[index].copy, structs[index].copy);
//		printf("\t|     size : %d\n", structs[index].size);
//		index++;
//	}
//}
