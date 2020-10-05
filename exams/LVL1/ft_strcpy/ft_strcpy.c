/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/24 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char 	*ft_strcpy(char *s1, char *s2)
{
	char *str;

	str = s1;
	while (*s2)
		*s1++ = *s2++;
	*s1='\0';
	return (str);
}

int main(void)
{
	char *str = "abcdef";
	char *dest;
	char *tmp;

	tmp = str;
	dest = (char *)malloc(7);
	dest = ft_strcpy(dest, str);
	printf("\noriginal: %s @ %p", tmp,  &tmp);
	printf("\nduplicat: %s @ %p\n", dest, &str);
}
