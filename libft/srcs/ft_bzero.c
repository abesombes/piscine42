/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:32:28 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/15 11:49:00 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    bzero(void *s, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        *(char *)s = '\0';
        i++;
    }
}
