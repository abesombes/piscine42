/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:11:09 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 17:29:36 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void    btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    btree_apply_suffix(root->left, applyf);
    btree_apply_suffix(root->right, applyf);
    printf("[%i]->", *((int*)root->item));
    (*applyf)(root->item);
    printf("[%i]\n", *((int*)root->item));
}
