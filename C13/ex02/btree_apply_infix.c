/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:39:56 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 17:31:19 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void    btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    btree_apply_infix(root->left, applyf);
    printf("[%i]->", *((int*)root->item));  
    (*applyf)(root->item);
    printf("[%i]\n", *((int*)root->item));  
    printf("[%i]->", *((int*)root->item));  
    (*applyf)(root->item);
    printf("[%i]\n", *((int*)root->item));  
    btree_apply_infix(root->right, applyf);
}
