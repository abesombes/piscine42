/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:11:54 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/16 11:38:55 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t needle_size;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	needle_size = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j])
			j++;
		if (j >= needle_size)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
