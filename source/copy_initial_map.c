/*
** EPITECH PROJECT, 2021
** copy_initial_file.c
** File description:
** made to stock initial map
*/

#include "sokoban.h"

int copy_initial_map(char *content)
{
    int fd = open("initial_map", O_RDWR | O_TRUNC | O_CREAT, 0755);
    int len = my_strlen(content);

    write(fd, content, len - 1);
    close(fd);
}
