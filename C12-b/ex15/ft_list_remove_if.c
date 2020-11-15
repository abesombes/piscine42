/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:03:52 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/08 14:21:24 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list *prev;
    t_list *l;

    prev = NULL;
    l = *begin_list;
    while (l)
        if (cmp(l->data, data_ref) == 0)
        {
            if (prev)
                prev->next = l->next;
            else
                *begin_list=l->next;
            free_fct(l->data);
            free(l);
            if (prev)
                l = prev->next;
            else
                l = *begin_list;
        }
        else
        {
            prev = l;
            l = l->next;
        }
}
