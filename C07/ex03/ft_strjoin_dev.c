/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/15 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int 	ft_strlen(char* str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_concat(char *str1, char *str2)
{
	int i;
	int k;
	char *dest;

	if ((!(dest = (char *)malloc(sizeof(char) * (ft_strlen(str1)+ft_strlen(str2)+1)))))
 		return NULL;	
	i = -1;
	while (str1[++i])
		dest[i] = str1[i];
	k = -1;
	while (str2[++k])
		dest[i++] = str2[k];
	return dest;
}


char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	char *conc_text;
	int fullsize;

	fullsize = 0;
	i = -1;
	while (strs[++i] && i < size)
		fullsize += ft_strlen(strs[i]);
	fullsize += ft_strlen(sep) * (i - 1);
	if ((!(conc_text = (char *)malloc(sizeof(char) * (fullsize + 1)))) || (size == 0))
 	{
		*conc_text = '\0';
		return conc_text;
	}
	i = -1;
	while (++i < size && strs[i])
	{
		conc_text = ft_concat(conc_text, strs[i]);
		if (i != size - 1)
			conc_text = ft_concat(conc_text, sep);
		printf("\nConcat: %s", conc_text);

	}
	conc_text[fullsize + 1] = '\0';
	return (conc_text);
}

int 	main (void)
{
	int size;
	char **strs;
	char *sep;

	//printf("sizeof(strs): %li", sizeof(strs));
	strs = (char**)malloc(sizeof(strs)*5);
	strs[0] = "hello";
	strs[1] = "my";
	strs[2] = "name";
	strs[3] = "is";
	strs[4] = "Alex";
	size = 5;
	sep = "@";
	printf("\nft_strjoin: %s\n", ft_strjoin(size, strs, sep));
	return (0);
}
