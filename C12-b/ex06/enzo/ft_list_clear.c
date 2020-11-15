#include <stdlib.h>

#include "ft_list.h"

#include <stdio.h>

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    if (begin_list->next != 0)
        ft_list_clear(begin_list->next, free_fct);
    (*free_fct)(begin_list->data);
    free(begin_list);
}

void    print_element(void *element)
{
    printf("element:: %d\n", *((int *)element));
    free(element);
}

void    ft_print_list(t_list *list)
{
    printf("list->next: %p\n", list->next);
    if (list->next == 0)
    {   
        printf("\nEmpty list!\n");
        return;
    }
        while (list->next != NULL)
    {
        printf("data -> [%i] | next -> [%p]\n", *((int *)list->data), (void *)(list->next));
        list = list->next;
    }
    printf("\n*--------------------------------------*\n");
}

int     main(void)
{
    int     *index;
    int     *malloced_index;
    t_list  *list;
    t_list  *tmp;

    index = malloc(sizeof(int));
    *index = 10;
    list = ft_create_elem(index);
    tmp = list;
    malloced_index = malloc(sizeof(int));
    *malloced_index = 15;
    //ft_print_list(list);
    ft_list_push_back(&list, (void *)malloced_index);
    ft_print_list(tmp);
    //ft_list_clear(list, &print_element);
    //ft_print_list(list);
}
