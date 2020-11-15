/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:04:18 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/10 00:41:27 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <assert.h>
void btree_print(t_btree *tr)
{
    printf("[%i]\n", *((int*)tr->item));
    if (tr->left != 0)
    {
        printf("/\n");
        btree_print(tr->left);
    }
    if (tr->right != 0)
    {
        printf("\\\n");
        btree_print(tr->right);
    }
    return;
}

void ft_triple(void *data)
{
    *(int *)data = *(int *)data * 3;
}

int ft_intcmp(void *data1, void *data2)
{
    return((*(int *)data1) - (*(int *)data2));
}

int main(void)
{
    int *nb;
    int *nb2;
    int *nb3;
    int *nb4;
    int *nb5;
    int *nb6;
    int *nb7;
    int *nb8;
    //char *item = "Hello, world!";
    t_btree *emptynode = NULL;
    t_btree *node;
    t_btree *node2;
    t_btree *node3;
    t_btree *node4;
    t_btree *node5;
    t_btree *node6;
    t_btree *node7;

    nb = malloc(sizeof(int));
    nb2 = malloc(sizeof(int));
    nb3 = malloc(sizeof(int));
    nb4 = malloc(sizeof(int));
    nb5 = malloc(sizeof(int));
    nb6 = malloc(sizeof(int));
    nb7 = malloc(sizeof(int));
    nb8 = malloc(sizeof(int));
    *nb = 10;
    *nb2 = 15;
    *nb3 = 20;
    *nb4 = 25;
    *nb5 = 30;
    *nb6 = 12;
    *nb7 = 28;
    *nb8 = 30;
    node = btree_create_node(nb3);
    node2 = btree_create_node(nb);
    node3 = btree_create_node(nb2);
    node6 = btree_create_node(nb6);
    node7 = btree_create_node(nb7);
    node->left=node6;
    node->right=node7;
    node4 = btree_create_node(nb4);
    node5 = btree_create_node(nb5);
    node6->left = node2;
    node6->right = node3;
    node7->left = node4;
    node7->right = node5;
    if (emptynode)
        btree_print(emptynode);
    if (node)
        btree_print(node);
    printf("*--------------------------*\n");
    //btree_insert_data(&emptynode, nb8, &ft_intcmp);
    //btree_insert_data(&node, nb8, &ft_intcmp);
    //btree_apply_suffix(node, &ft_triple);
    //printf("*--------------------------*\n");
    //btree_print(node);
    printf("Element trouvé? %i", *(int *)btree_search_item(node, nb3, &ft_intcmp));
    //btree_search_item(node, nb2, &ft_intcmp);
    //btree_print(emptynode);
    free(node);
}
