/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char *str2 = malloc(sizeof(char) * (len + 1));
    len -= 1;
    for (int x = 0; x <= my_strlen(str); x += 1) {
        str2[x] = str[len];
        len -= 1;
    }
    return (str2);
}
