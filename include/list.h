/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** list.h
*/

#ifndef LIST_H
# define LIST_H

#include <stddef.h>
#include <unistd.h>
#include <errno.h>

typedef struct list_s
{
    struct list_s *next;
    struct list_s *prev;
    char freed;
    size_t size;
    void *ptr;
} list_t;

enum booleans_e
{
    FALSE,
    TRUE,
};

enum alloc_return_value_e
{
    ALLOC_FAIL = -1,
    ALLOC_SUCCESS = 0,
};

extern list_t *_HEAD;

#define _LIST_SIZE   (sizeof(list_t))
#define _DOUBLE_PAGE (getpagesize() * 2)

int addback(const size_t *const nb);
int addfront(const size_t *const nb);

#endif