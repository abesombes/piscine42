/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:47:21 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/16 22:35:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void *dst;

	if (!dest && !src)
		return (NULL);
	dst = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (dst);
}
