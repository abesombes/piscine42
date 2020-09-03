/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:55:02 by abesombes        #+#     #+#             */
/*   Updated: 2020/05/28 18:55:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char 	*ft_strlowercase(char *str)
{
	int i;
	int j;
	char *uppercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	i = 0;
	while(str[i])
	{
		j = 0;
		while(uppercase[j])
		{
			if (uppercase[j]==str[i])
				str[i] = str[i] + 32;
		j++;
		}
	i++;
	}
return (str);	
}

int ft_is_alphanumeric(char c)
{
	int i;
	int is_alphanumeric;
	char *upperlowercase="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *digits="0123456789";

	is_alphanumeric = 0;
	i = -1;
	while (upperlowercase[++i])
	{
	if (c == upperlowercase[i])
		is_alphanumeric = 1;
	}
	i = -1;
	while (digits[++i])
	{
	if (c == digits[i])
		is_alphanumeric = 2;
	}
	return (is_alphanumeric);
}


char 	*ft_strcapitalize(char *str)
{	
	int i;
	int j;

	
	str[0]=str[0]-32;
	i = 1;
	while (str[i]!='\0')
	{
		if ((ft_is_alphanumeric(str[i-1]) == 0) && (ft_is_alphanumeric(str[i]) == 1))
			str[i]=str[i]-32;
		i++;
	}
	return(str);
}

int 	main(void)
{
	char str[70] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char test = '.';

	printf("STR: %s", str);
//	printf("\nIS ALPHANUMERIC? : %i", ft_is_alphanumeric(test));
	printf("\nSTR LOWERCASED: %s\n", ft_strlowercase(str));
	printf("\nSTR CAPITALIZED: %s\n", ft_strcapitalize(str));
}
