/*
** EPITECH PROJECT, 2020
** print_error_msg
** File description:
** to display errors
*/

#include <unistd.h>

void put_error_char(char c)
{
    write(2, &c, 1);
}

int print_error_msg(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        put_error_char(str[i]);
        i += 1;
    }
}
