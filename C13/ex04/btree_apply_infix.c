/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:39:56 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/09 16:33:32 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void    btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;
    if (root->left)
        btree_apply_infix(root->left, applyf);
    else
    {   
        printf("[%i]->", *((int*)root->item));  
        (*applyf)(root->item);
        printf("[%i]\n", *((int*)root->item));  
    }
    if (root->left)
    {
        printf("[%i]->", *((int*)root->item));  
        (*applyf)(root->item);
        printf("[%i]\n", *((int*)root->item));  
    }
    if (root->right)
        btree_apply_infix(root->right, applyf);
}
