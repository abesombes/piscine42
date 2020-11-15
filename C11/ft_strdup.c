/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/14 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int 	ft_strlen(char *str)
{
	int count;
	
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char *str;
	int i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(src) + 1))))
	return (NULL);
	while (src[i] != '\0')
	{
	
			str[i] = src[i];
			i++;
	}
	str[i] = '\0';
	return (str);
}

int 	main (int argc, char **argv)
{
	char *tmp;
	if (argc == 0)
		return (0);
	if (argc >= 1)
	{
	tmp = ft_strdup(argv[1]);
	printf("\nsrc: %s", tmp);
	free(tmp);
	}
}
