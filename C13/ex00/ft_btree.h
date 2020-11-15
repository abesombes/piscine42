/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:48:33 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 10:52:55 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
#define FT_BTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_btree
{
    void *item;
    s_btree *left;
    s_btree *right;
}               t_btree;

t_btree *btree_create_node(void *item);

#endif
