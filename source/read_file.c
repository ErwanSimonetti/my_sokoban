/*
** EPITECH PROJECT, 2021
** read_file.c
** File description:
** made to read file content
*/

#include "sokoban.h"

long int find_buff(char const *filepath)
{
    struct stat buffer;

    stat(filepath, &buffer);
    return (buffer.st_size);
}

char *read_file(const char *title)
{
    long size = find_buff(title);
    int fd = open(title, O_RDONLY);
    char *buff = malloc(sizeof(char)* (size + 1));
    int offset = 0;
    int len;

    while ((len = read(fd, buff + offset, size - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    close(fd);
    return (buff);
}
