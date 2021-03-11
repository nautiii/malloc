/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** alloc.h
*/

#ifndef ALLOC_HPP
# define ALLOC_HPP

#include <stddef.h>
#include <stdint.h>
#include <errno.h>

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif