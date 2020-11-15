/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:34:41 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/08 18:46:53 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
        t_list *e;

            if (!*begin_list || cmp(data, (*begin_list)->data) <= 0)
                    {
                                if (!(e = ft_create_elem(data)))
                                                return ;
                                        e->next = *begin_list;
                                                *begin_list = e;
                                                    }
                else
                            ft_sorted_list_insert(&(*begin_list)->next, data, cmp);
}


void ft__sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list *curr;
    t_list *prev;
    t_list *new_elem;
    int injected;

    prev = NULL;
    injected = 0;
    curr = *begin_list;
    new_elem = ft_create_elem(data);
    while(curr && injected == 0)
    {
        if (cmp(curr->data, data) >= 0)
        {
            if (prev)
                prev->next = new_elem;
            else
                *begin_list = new_elem;
            new_elem->next = curr;
            injected = 1;
            return;
        }
        prev = curr;
        curr = curr->next;
        if (prev->next == NULL && injected == 0)
            prev->next = new_elem;
    }
}
