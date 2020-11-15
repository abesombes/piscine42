/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:39:33 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/06 15:09:52 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *tmp;

    while (begin_list)
    {   
        tmp = begin_list;
        begin_list = begin_list->next;
        if (free_fct)
            free_fct(tmp->data);
        free(tmp);
        tmp = 0;
    }
}
