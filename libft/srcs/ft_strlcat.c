/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 08:21:57 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/16 09:09:36 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_size;
	size_t src_size;
	size_t i;
	size_t j;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (src_size + size);
	i = 0;
	while (dst[i])
		i++;
	j = -1;
	while (++j < size - dst_size - 1 && src[j])
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (dst_size + src_size);
}
