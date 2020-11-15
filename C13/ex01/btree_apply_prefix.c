/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:03:54 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 17:32:06 by alexandre        ###   ########.fr       */
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
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}
