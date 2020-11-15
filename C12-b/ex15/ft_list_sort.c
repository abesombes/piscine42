/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:03:46 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/08 16:11:19 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list *curr;
    int swap;
    void *tmp;

    curr = *begin_list;
    while(curr && curr->next)
    {
        swap = 0;
        if (cmp(curr->data, curr->next->data) > 0)
        {
            tmp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = tmp;
            curr = *begin_list;
            swap = 1;
        }
        if (!swap)
            curr = curr->next;
    }
}
