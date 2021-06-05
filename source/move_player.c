/*
** EPITECH PROJECT, 2021
** move_player.c
** File description:
** moves player with arrow
*/

#include "sokoban.h"

int find_player(char *content)
{
    int count = 0;

    while (content[count] != 'P')
        count += 1;
    return (count);
}

int find_line_len(char *map)
{
    int count = 0;

    while (map[count] != '\n')
        count += 1;
    return (count);
}

char find_movement(int key)
{
    switch (key) {
    case 65:
        return ('u');
        break;
    case 66:
        return ('d');
        break;
    case 67:
        return ('r');
        break;
    case 68:
        return ('l');
        break;
    }
}

char find_next_pos(int cursor_player, char movement, char *map)
{
    int line_len = find_line_len(map);

    switch (movement) {
    case 'u':
        return (map[cursor_player - line_len - 1]);
        break;
    case 'd':
        return (map[cursor_player + line_len + 1]);
        break;
    case 'r':
        return (map[cursor_player + 1]);
        break;
    case 'l':
        return (map[cursor_player - 1]);
        break;
    }
}

char *move_player(int key, char *map, int *locations)
{
    int cursor_player = find_player(map);
    char movement = find_movement(key);
    char next_pos = find_next_pos(cursor_player, movement, map);

    if (next_pos == ' ' || next_pos == 'O')
        return (move_space(movement, map, locations));
    else if (next_pos == 'X')
        return (move_crate(movement, map, locations));
    else
        return (map);
}
