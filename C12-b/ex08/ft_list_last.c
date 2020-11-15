/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:29:46 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/05 16:03:20 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list  *ft_list_last(t_list *begin_list)
{
    while (begin_list->next)
    {
        begin_list=begin_list->next;
    }
    return (begin_list);
}
