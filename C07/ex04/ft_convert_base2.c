*/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/16 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char *ft_concat(char *str1, char str2)
{
	int i;

	i = -1;
	while (str1[++i]);
	str1[++i] = str2;
	return (str1);
}

char* ft_putnbr_base(int nbr, char* str, char *base_to)
{
        int sze;
        int i;

        sze = 0;
	i = -1;
        while (base_to[++i])
                sze++;
//	printf("\nnbr: %i", nbr);
//	printf("\nsze: %i", sze);
//	printf("\nnbr modulo sze : %i", nbr % sze);
	i = -1;
        if (nbr < 0)
        {
		str = ft_concat(str,'-');
		nbr = -nbr;
        }
        if (nbr > sze)
                ft_putnbr_base(nbr/sze, str, base_to);
        if (nbr % sze > 9)
	{
		printf("\nnbr: %i - sze %i - nbr modulo sze %i - base_to %s", nbr, sze, nbr % sze, base_to);
                str = ft_concat(str, base_to[nbr % sze]);
        	printf("\nstr: %s", str);
	}
	else
	{
                str = ft_concat(str, (char)(nbr % sze));
		return (str);
	}
}
