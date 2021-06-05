/*
** EPITECH PROJECT, 2020
** unit_tests for minishell
** File description:
** criterion
*/

#include "unit_test_minishell.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
