/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:53:08 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 11:11:54 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
    t_btree *node;

    if (!(node = (t_btree *)malloc(sizeof(t_btree))))
        return (0);
    node->item = item;
    node->left = 0;
    node->right = 0;
    return (node);
}
