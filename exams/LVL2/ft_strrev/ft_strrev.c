/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/25 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strrev(char *str)
{
	char tmp;
	int size;
	int i;

	size = 0;
	while (str[size])
		size++;
	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = tmp;
		i++;
	}
	return (str);
}

int main(void)
{
	char str1[6] = "123456";

	printf("\nstr1: %s", str1);
 	printf("\nrev_str1: %s\n", ft_strrev(str1));
}
