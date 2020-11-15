/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:53:56 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 18:50:28 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree__insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
    if (*root == NULL)
    {
        *root = btree_create_node(item);
        return;
    }
    if ((*cmpf)(item, (*root)->item) >= 0 && (*root)->right == NULL)
        (*root)->right = btree_create_node(item);
    else if ((*cmpf)(item, (*root)->item) >= 0)
        btree_insert_data(&((*root)->right), item, cmpf);
    else if ((*cmpf)(item, (*root)->item) < 0 && (*root)->left == NULL)
        (*root)->left = btree_create_node(item);
    else if ((*cmpf)(item, (*root)->item) < 0)
        btree_insert_data(&((*root)->left), item, cmpf);
}

void    btree_insert_data(t_btree **root, void *item,
        int (*cmpf)(void *, void *))
{
    if (!*root)
        *root = btree_create_node(item);
    else if (cmpf(item, (*root)->item) < 0)
        btree_insert_data(&(*root)->left, item, cmpf);
    else
        btree_insert_data(&(*root)->right, item, cmpf);
}
