/*
** EPITECH PROJECT, 2021
** display_usage.c
** File description:
** for my_sokoban
*/

#include "sokoban.h"

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap\tfile representing the warehouse map, containing '#'");
    my_putstr(" for walls,\n");
    my_putstr("\t\t'P' for the player, 'X' for boxes and 'O'");
    my_putstr("for storage locations.\n");
}
