/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:04:18 by alexandre         #+#    #+#             */
/*   Updated: 2020/11/10 15:19:03 by alexandre        ###   ########.fr       */
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
    int *nb9;
    int *nb10;
    t_btree *emptynode = NULL;
    t_btree *node;
    t_btree *node2;
    t_btree *node3;
    t_btree *node4;
    t_btree *node5;
    t_btree *node6;
    t_btree *node7;
    t_btree *node8;
    t_btree *node9;
    t_btree *node10;

    nb = malloc(sizeof(int));
    nb2 = malloc(sizeof(int));
    nb3 = malloc(sizeof(int));
    nb4 = malloc(sizeof(int));
    nb5 = malloc(sizeof(int));
    nb6 = malloc(sizeof(int));
    nb7 = malloc(sizeof(int));
    nb8 = malloc(sizeof(int));
    nb9 = malloc(sizeof(int));
    nb10 = malloc(sizeof(int));
    *nb = 5;
    *nb2 = 10;
    *nb3 = 12;
    *nb4 = 15;
    *nb5 = 20;
    *nb6 = 22;
    *nb7 = 25;
    *nb8 = 27;
    *nb9 = 30;
    *nb10 = 35;
    node = btree_create_node(nb);
    node2 = btree_create_node(nb2);
    node3 = btree_create_node(nb3);
    node4 = btree_create_node(nb4);
    node5 = btree_create_node(nb5);
    node6 = btree_create_node(nb6);
    node7 = btree_create_node(nb7);
    node8 = btree_create_node(nb8);
    node9 = btree_create_node(nb9);
    node10 = btree_create_node(nb10);
    node7->left = node6;
    node7->right = node9;
    node9->left = node8;
    node9->right = node10;
    node6->left = node4;
    node4->left = node3;
    node4->right = node5;
    node10->right = node2;
    node2->right = node;
    if (emptynode)
        btree_print(emptynode);
    if (node7)
        btree_print(node7);
    printf("*--------------------------*\n");
    printf("Max Depth? %i\n", btree_level_count(node7));
    free(node);
}
