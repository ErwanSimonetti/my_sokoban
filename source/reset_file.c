/*
** EPITECH PROJECT, 2021
** reset_file.c
** File description:
** reset file
*/

#include "sokoban.h"

void reset_file(const char *title)
{
    char *old_content = read_file("initial_map");
    int fd = open(title, O_WRONLY);

    write(fd, old_content, my_strlen(old_content));
    close(fd);
}
