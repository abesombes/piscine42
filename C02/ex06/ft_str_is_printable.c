/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/26 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int 	ft_str_is_printable(char *str)
{
	int i;
	int j;
	int is_printable;
	
	is_printable=0;
	i = 0;
	j = 0;
	while (str[j]!='\0')
		j++;
	while (str[i]!='\0')
	{
		if ((str[i]>=32)&&(str[i]!=127))
			is_printable++;
		i++;
	}
	if (is_printable==j)
		return (1);
	else
		return (0);
}

int	main(void)
{
	char *str;

	str="testforce4";
	printf("STR: %s", str);
	printf("\nIS PRINTABLE? %i\n", ft_str_is_printable(str));
}

