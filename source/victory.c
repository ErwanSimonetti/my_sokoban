/*
** EPITECH PROJECT, 2021
** victory.c
** File description:
** made to know if the game is won
*/

#include "sokoban.h"

int game_won(char *map, int *locations)
{
    int count = 0;

    while (count != locations[0] - 1) {
        if (map[locations[count + 1]] != 'X')
            return (0);
        count += 1;
    }
    return (-1);
}