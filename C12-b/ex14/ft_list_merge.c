/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:34:53 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/08 14:57:59 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list *curr;
    if (*begin_list1)
        curr = *begin_list1;
    else
    {
        *begin_list1 = begin_list2;
        return;
    }
    while (curr->next)
        curr=curr->next;
    curr->next = begin_list2;
}
