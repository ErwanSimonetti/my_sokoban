/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** duplicate a string
*/

#include <stdlib.h>

int my_strlen(char const *src);

char my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *str;
    int size_src;

    size_src = my_strlen(src);
    str = malloc(sizeof(char) * (size_src + 1));
    my_strcpy(str, src);
    return (str);
}
