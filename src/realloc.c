/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** realloc.c
*/

#include "alloc.h"
#include "list.h"

static void *move_chunck(size_t size, list_t *tmp, void **ptr)
{
    void *addr = malloc(size);
    void *save = addr;

    while (size--)
        *((char *)addr++) = *((const char *)tmp->ptr++);
    free(*ptr);
    return save;
}

void *realloc(void *ptr, size_t size)
{
    list_t *tmp = _HEAD;

    if (!ptr)
        return malloc(size);
    while (tmp) {
        if (tmp->ptr == ptr)
            break;
        tmp = tmp->next;
    }
    if (!tmp)
        return malloc(size);
    if (!size) {
        free(tmp->ptr);
        return NULL;
    }
    if (tmp->size >= size) {
        tmp->size = size;
        return tmp->ptr;
    }
    return move_chunck(size, tmp, &ptr);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if ((long long unsigned int)nmemb * size > SIZE_MAX) {
        errno = ENOMEM;
        return NULL;
    }
    return realloc(ptr, nmemb * size);
}
