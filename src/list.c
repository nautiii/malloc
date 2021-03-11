/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** list.c
*/

#include "list.h"

list_t *_HEAD = NULL;

static size_t alloc_size(const size_t *const size)
{
    return (((*size + _LIST_SIZE) /_DOUBLE_PAGE) * _DOUBLE_PAGE) +
            (((*size + _LIST_SIZE) % _DOUBLE_PAGE) ? _DOUBLE_PAGE : 0);
}

static int newpages(const size_t *const size)
{
    size_t nb = alloc_size(size);

    return (!_HEAD) ? addfront(&nb) : addback(&nb);
}

static void split(const size_t *const size, list_t *const *const save)
{
    list_t *rest = (*save)->ptr + *size;

    rest->size = (*save)->size - *size - _LIST_SIZE;
    rest->ptr = rest + 1;
    rest->freed = TRUE;
    rest->prev = NULL;
    rest->next = (*save)->next;
    (*save)->next = rest;
}

void *newaddr(const size_t *const size)
{
    list_t *save = NULL;

    for (list_t *tmp = _HEAD; tmp != NULL; tmp = tmp->next)
        if (tmp->freed == TRUE && tmp->size >= *size)
            save = (!save || save->size > tmp->size) ? tmp : save;
    if (!save)
        return (newpages(size) == ALLOC_FAIL) ? NULL : newaddr(size);
    // if (save->size - *size > _LIST_SIZE)
    //     split(size, &save);
    save->freed = FALSE;
    save->size = *size;
    return save->ptr;
}