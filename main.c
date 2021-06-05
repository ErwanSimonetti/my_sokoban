/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function for my_sokoban
*/

#include "sokoban.h"

int main (int ac, char **av, char **env)
{
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        display_usage();
    else if (check_errors(ac, av) == 84)
        return (84);
    else {
        //adjust_map(av[1]);
        return (my_sokoban(av[1]));
    }
}
