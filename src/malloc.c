/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** malloc.c
*/

#include "alloc.h"

void *newaddr(const size_t *const);

static void convert_size(size_t *const size)
{
    size_t count = 0;

    if (*size > 1 && !(*size & (*size - 1)))
        return ;
    while (*size >> count)
        ++count;
    *size = 1;
    *size <<= (count) ? count : 1;
}

void *malloc(size_t size)
{
    if (!size || (long long int)size < 0)
        return NULL;
    convert_size(&size);
    return newaddr(&size);
}

void *calloc(size_t nmemb, size_t size)
{
    void *addr = NULL;
    void *save = NULL;

    if ((long long unsigned int)(nmemb * size) > SIZE_MAX) {
        errno = ENOMEM;
        return NULL;
    }
    addr = malloc(nmemb * size);
    if (!addr)
        return NULL;
    save = addr;
    for (size = nmemb * size; size; size--)
        *((char *)addr++) = 0;
    return save;
}