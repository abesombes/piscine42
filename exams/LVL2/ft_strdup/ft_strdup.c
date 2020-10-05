/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c            	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/28 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;
	while (str[i])
		i++;
	return(i);
}

char    *ft_strdup(char *src)
{
	int i;
	char *dup;

	if (!(dup = (char *)malloc(sizeof(char)*ft_strlen(src)+1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i]='\0';
	return (dup);
}

int main(void)
{
	char *str1 = "test";
	char *dupl;

	dupl = ft_strdup(str1);
	printf("\nstr1: %s @ %p | duplicate: %s @ %p\n", str1, &str1, dupl, &dupl);
}
