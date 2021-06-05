/*
** EPITECH PROJECT, 2021
** adjust_map.c
** File description:
** made to make map even
*/

#include "sokoban.h"

char *malloc_map(char *map, int *longest_line)
{
    int longest_line_temp = 0;
    int number_of_lines = 0;
    int count = 0;

    while (map[count] != '\0') {
        if (map[count] == '\n') {
            if (longest_line_temp > longest_line[0])
                longest_line[0] = longest_line_temp;
            longest_line_temp = 0;
            number_of_lines += 1;
        }
        longest_line_temp += 1;
        count += 1;
    }
    return (malloc(sizeof(char) * ((longest_line[0] + 1) * number_of_lines)));
}

int adjust_len(char *new_map, int longest_line, int current_len, int count)
{
    while (current_len < longest_line) {
        new_map[count] = ' ';
        current_len += 1;
        count += 1;
    }
    new_map[count] = '\n';
    return (count);
}

void write_adjusted_map(const char *title, char *map)
{
    int fd = open(title, O_WRONLY);

    write(fd, map, my_strlen(map));
    close (fd);
}

char *adjust_map(char *map)
{
    int *longest_line = malloc(sizeof(int));
    char *new_map = malloc_map(map, longest_line);
    int count_old = 0;
    int count_new = 0;
    int current_len = 1;

    while (map[count_old] != '\0') {
        if (map[count_old] == '\n') {
            count_new = adjust_len(new_map, longest_line[0], current_len,
            count_new);
            current_len = 0;
        } else {
            new_map[count_new] = map[count_old];
        }
        current_len += 1;
        count_old += 1;
        count_new += 1;
    }
    return (new_map);
}