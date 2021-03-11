/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** free.c
*/

#include "alloc.h"
#include "list.h"

void free(void *ptr)
{
    list_t *tmp = _HEAD;

    if (!ptr)
        return ;
    while (tmp) {
        if (tmp->ptr == ptr)
            break;
        tmp = tmp->next;
    }
    if (tmp)
        tmp->freed = TRUE;
}