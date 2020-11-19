/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:52:12 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/19 22:54:10 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*jstr;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	size_s1 = (s1 ? ft_strlen(s1) : 0);
	size_s2 = (s2 ? ft_strlen(s2) : 0);
	if (!(jstr = (char *)malloc(size_s1 + size_s2 + 1)))
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
		{
			jstr[i] = s1[i];
			i++;
		}
	j = 0;
	if (s2)
		while (s2[j])
			jstr[i++] = s2[j++];
	jstr[i] = '\0';
	return (jstr);
}
