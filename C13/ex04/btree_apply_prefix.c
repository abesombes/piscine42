/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:03:54 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 12:25:41 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void    btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    printf("[%i]\n", *((int*)root->item));
    (*applyf)(root->item);
    printf("[%i]\n", *((int*)root->item));
    if (root->left)
        btree_apply_prefix(root->left, applyf);
    if (root->right)
        btree_apply_prefix(root->right, applyf);
}
