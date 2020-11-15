/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:04:39 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/06 19:05:53 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
    t_list *prev;
    t_list *next;

    prev = NULL;
    while (*begin_list)
    {
        next = (*begin_list)->next;
        (*begin_list)->next = prev;
        prev = *begin_list;
        *begin_list = next;
    }
    *begin_list = prev;
}
