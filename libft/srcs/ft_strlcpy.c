/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 06:45:09 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/17 21:44:59 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t src_size;

	i = -1;
	if (!src)
		return (0);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	while (++i < size - 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (src_size);
}
