/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:20:05 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/08 16:28:21 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_reverse_fun(t_list *begin_list)
{
    t_list *curr;
    t_list *to_swap;
    void *tmp;
    int i;
    int size;

    i = 0;
    curr = begin_list;
    size = ft_list_size(curr);
    while (i < size / 2)
    {
        curr = ft_list_at(begin_list, i);
        to_swap = ft_list_at(begin_list, size - i - 1);
        tmp = curr->data;
        curr->data = to_swap->data;
        to_swap->data = tmp;
        i++;
    }
}
