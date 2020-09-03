/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_strupcase.c    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/27 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char 	*ft_strupcase(char *str)
{	
	int i;
	int j;
	char *lowercase="abcdefghijklmnopqrstuvwxyz";
	
	i = 0;
	while (str[i]!='\0')
	{
	j = -1;
	while (lowercase[++j])
		{
		if (lowercase[j] == str[i])
			str[i] = str[i] - 32;
		}
	i++;
	}
	return(str);
}

int 	main(void)
{
	char str[10] = "ao.jofjd";
	
	printf("STR: %s", str);
	printf("\nSTR UPCASE: %s\n", ft_strupcase(str));
}
