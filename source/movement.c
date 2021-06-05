/*
** EPITECH PROJECT, 2021
** movement.c
** File description:
** made to write a new map with new positions of player for sokoban
*/

#include "sokoban.h"

int find_next_pos_cursor(char *map, int cursor_player, char movement)
{
    int line_len = find_line_len(map);

    switch (movement) {
    case 'u':
        return (cursor_player - line_len - 1);
        break;
    case 'd':
        return (cursor_player + line_len + 1);
        break;
    case 'r':
        return (cursor_player + 1);
        break;
    case 'l':
        return (cursor_player - 1);
        break;
    }
}

int find_crate(int cursor_player, char movement, char *map)
{
    int line_len = find_line_len(map);

    switch (movement) {
    case 'u':
        return (cursor_player - line_len - 1);
        break;
    case 'd':
        return (cursor_player + line_len + 1);
        break;
    case 'r':
        return (cursor_player + 1);
        break;
    case 'l':
        return (cursor_player - 1);
        break;
    }
}

char *move_space(char movement, char *map, int *locations)
{
    int cursor_player = find_player(map);
    char *new_map = malloc(sizeof(char) * my_strlen(map));
    int count = 0;
    int next_pos_cursor = find_next_pos_cursor(map, cursor_player, movement);

    while (map[count] != '\0') {
        if (count == next_pos_cursor)
            new_map[count] = 'P';
        else if (is_o(count, locations) == -1 && map[count] != 'X')
            new_map[count] = 'O';
        else if (count == cursor_player)
            new_map[count] = ' ';
        else
            new_map[count] = map[count];
        count += 1;
    }
    return (new_map);
}

char *move_crate(char movement, char *map, int *locations)
{
    int cursor_player = find_player(map);
    int cursor_crate = find_crate(cursor_player, movement, map);
    char *new_map = malloc(sizeof(char) * my_strlen(map));
    char next_pos_crate = find_next_pos(cursor_crate, movement, map);
    int count = 0;
    int next_pos_cursor = find_next_pos_cursor(map, cursor_player, movement);
    int next_crate_pos_cursor = find_next_pos_cursor(map, cursor_crate,
    movement);

    if (next_pos_crate != '#' && next_pos_crate != 'X') {
        while (map[count] != '\0') {
            if (count == next_pos_cursor)
                new_map[count] = 'P';
            else if (count == next_crate_pos_cursor)
                new_map[count] = 'X';
            else if (is_o(count, locations) == -1 && map[count] != 'X')
                new_map[count] = 'O';
            else if (count == cursor_player || count == cursor_crate)
                new_map[count] = ' ';
            else
                new_map[count] = map[count];
            count += 1;
        }
        return (new_map);
    } else
        return (map);
}