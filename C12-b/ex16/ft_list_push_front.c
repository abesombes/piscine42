/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:36:40 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/05 14:36:51 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new_elem;

    new_elem = ft_create_elem(data);
    new_elem->next = *begin_list;
    *begin_list = new_elem;
}
