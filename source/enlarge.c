/*
** EPITECH PROJECT, 2021
** enlarge.c
** File description:
** made to display a message until terminal is enough enlarged
*/

#include "sokoban.h"

int get_nb_columns(char *content)
{
    int count = 0;

    while (content[count] != '\n')
        count += 1;
    return (count);
}

int get_nb_lines(char *content)
{
    int count = 0;
    int lines = 0;

    while (content[count] != '\0') {
        if (content[count] == '\n')
            lines += 1;
        count += 1;
    }
    return (lines);
}

int enlarge(char *content)
{
    int lines = get_nb_lines(content);
    int columns = get_nb_columns(content);

    while (LINES <= lines || COLS <= columns) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 8, "ENLARGE TERMINAL");
        refresh();
    }
    return (0);
}
