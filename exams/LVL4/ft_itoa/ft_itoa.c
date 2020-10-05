/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c 	        	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/10/05 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_len(int nbr)
{
	int len;

	len = 0;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	len++;
	return (len);
}

char *ft_concat(char *str, char c, int len)
{
	int i;

	while (len >= 0)
	{
		str[len + 1] = str[len];
		len--;
	}
	str[0] = c;
	i = 0;
	while (str[i++]);
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int nbr)
{
	char *str;
	int len;
	int sign;

	sign = 1;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return ("-2147483648");
		nbr = -nbr;
		sign = -1;
	}
	len = ft_len(nbr);
	len = ((sign < 0)? len + 1: len);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (nbr > 9)
	{
		ft_concat(str, nbr % 10 + '0', len);
		nbr /= 10;
	}
	ft_concat(str, nbr % 10 + '0', len);
	if (sign < 0)
		ft_concat(str, '-', len);
	return (str);
}

int 	main(void)
{
	int nb;

	nb = -2147483648;
	printf("%i: |%s|", nb, ft_itoa(nb));
}
