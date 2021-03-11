/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** debug.c
*/

#include "list.h"
#include <stdio.h>

void print(void)
{
    char s[10] = {0};
    char c = 0;

    for (list_t *tmp = _HEAD; tmp; tmp=tmp->next) {
        c = (tmp->freed) ? '1' : '0';
        write(1, "LIST INFO -> is freed ? ", 24);
        write(1, &c, 1);
        write(1, " , size of block ? ", 19);
        sprintf(s, "%ld", tmp->size);
        write(1, s, 4);
        write(1, " , addr ? ", 4);
        sprintf(s, "%lx", (long unsigned int)tmp);
        write(1, s, 10);
        write(1, " , ", 3);
        sprintf(s, "%lx", (long unsigned int)tmp->ptr);
        write(1, s, 10);
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}