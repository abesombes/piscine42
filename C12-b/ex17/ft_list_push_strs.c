/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:45:00 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/05 21:50:19 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
    int i;
    t_list *begin;
    t_list *elem;
    
    i = 0;
    begin = 0;
    while (i < size && strs[i])
    {
        elem = ft_create_elem(strs[i]);
        elem->next = begin;
        begin = elem;
        i++;
    }
    return (begin);
}
