/*
** EPITECH PROJECT, 2021
** defeat.c
** File description:
** made to check if player lost the game
*/

#include "sokoban.h"

int cornered(int *obstructions)
{
    if (obstructions[0] == 1 && obstructions[1] == 1)
        return (-1);
    if (obstructions[1] == 1 && obstructions[2] == 1)
        return (-1);
    if (obstructions[2] == 1 && obstructions[3] == 1)
        return (-1);
    if (obstructions[3] == 1 && obstructions[0] == 1)
        return (-1);
    return (0);
}

int *init_obstructions(void)
{
    int *obstructions = malloc(sizeof(int) * 4);

    obstructions[0] = 0;
    obstructions[1] = 0;
    obstructions[2] = 0;
    obstructions[3] = 0;
    return (obstructions);
}

int cannot_move(char *map, int count)
{
    int line_len = find_line_len(map);
    int count_obstruction = 0;
    int *obstructions = init_obstructions();

    if (map[count + 1] == '#' || map[count + 1] == 'X')
        obstructions[2] = 1;
    if (map[count - 1] == '#' || map[count - 1] == 'X')
        obstructions[0] = 1;
    if (map[count + line_len + 1] == '#' || map[count + line_len + 1] == 'X')
        obstructions[3] = 1;
    if (map[count - line_len - 1] == '#' || map[count - line_len - 1] == 'X')
        obstructions[1] = 1;
    if (cornered(obstructions))
        return (-1);
    else
        return (0);
}

int game_lost(char *map)
{
    int count = 0;

    while (map[count] != '\0') {
        if (map[count] == 'X')
            if (cannot_move(map, count) == 0)
                return (0);
        count += 1;
    }
    return (-1);
}