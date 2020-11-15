/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:24:49 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/10 09:30:32 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void*))
{
    void *item;

    if (!root)
    return (NULL);
    if ((item = btree_search_item(root->left, data_ref, cmpf)))
        return (item);
    if (cmpf(root->item, data_ref) == 0)
        return (root->item);
    return (btree_search_item(root->right, data_ref, cmpf));
}
