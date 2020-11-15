/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:06:08 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/05 19:43:09 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *new_elem;
    t_list *ptr;

    new_elem = ft_create_elem((void *)data);
    if (!*begin_list)
    {
        *begin_list = new_elem;
        return;
    }
    ptr = *begin_list;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = new_elem;
}
