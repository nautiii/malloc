/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** unit_tests.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "alloc.h"
#include "list.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
}

Test(alloc, implemented_functions)
{
    size_t nb = 1;

    void *ptr = malloc(1);
    calloc(1, sizeof(char));
    ptr = realloc(ptr, 2);
    void *addr = malloc(16000);
    cr_assert_eq(realloc(&nb, 0), NULL);
}