/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:29:57 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/05 01:11:36 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list  *ft_create_elem(void *data)
{
    t_list *elem;

    if (!(elem = (t_list *)malloc(sizeof(t_list) * 1)))
        return (0);
    elem->data = data;
    elem->next = 0;
    return (elem);
}
