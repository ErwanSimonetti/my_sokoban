/*
** EPITECH PROJECT, 2021
** manage_o.c
** File description:
** made to stock all O's places
*/

#include "sokoban.h"

int *stock_o(char *map)
{
    int cursor = 0;
    int cursor_locations = 1;
    int *locations = malloc(sizeof(int) * my_strlen(map));

    while (map[cursor] != '\0') {
        if (map[cursor] == 'O') {
            locations[cursor_locations] = cursor;
            cursor_locations += 1;
        }
        cursor += 1;
    }
    locations[0] = cursor_locations;
    return (locations);
}

int is_o(int cursor_searched, int *locations)
{
    int cursor = 1;

    while (cursor != locations[0]) {
        if (locations[cursor] == cursor_searched)
            return (-1);
        cursor += 1;
    }
    return (0);
}