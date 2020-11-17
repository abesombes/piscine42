/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:38:12 by abesombe          #+#    #+#             */
/*   Updated: 2020/11/17 19:49:39 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*addr;
	size_t			i;

	addr = s;
	i = 0;
	while (i < n)
	{
		addr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
