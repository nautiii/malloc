/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** oplist.c
*/

#include "list.h"

int addback(const size_t *const nb)
{
    list_t *tmp = _HEAD;

    while (tmp->next)
        tmp = tmp->next;
    tmp->next = sbrk(*nb);
    if (tmp->next == (void *)-1)
        return ALLOC_FAIL;
    tmp->next->next = NULL;
    tmp->next->prev = NULL;
    tmp->next->freed = TRUE;
    tmp->next->size = *nb - _LIST_SIZE;
    tmp->next->ptr = tmp->next + 1;
    return ALLOC_SUCCESS;
}

int addfront(const size_t *const nb)
{
    _HEAD = sbrk(*nb);
    if (_HEAD == (void *)-1)
        return ALLOC_FAIL;
    _HEAD->next = NULL;
    _HEAD->prev = NULL;
    _HEAD->freed = TRUE;
    _HEAD->size = *nb - _LIST_SIZE;
    _HEAD->ptr = _HEAD + 1;
    return ALLOC_SUCCESS;
}