/*
** EPITECH PROJECT, 2020
** check_errors
** File description:
** for my_sokoban
*/

#include "sokoban.h"

int file_exists(char *title)
{
    int fd = open(title, O_RDONLY);

    if (fd == -1) {
        print_error_msg("error: file '");
        print_error_msg(title);
        print_error_msg("' does not exist\n");
        return (84);
    }
}

int content_valid(char *title)
{
    char *content = read_file(title);
    int count = 0;

    while (content[count] != '\0') {
        if (content[count] != ' ' && content[count] != '\n' && content[count]
            != '#' && content[count] != 'X' && content[count] != 'O' &&
            content[count] != 'P') {
            print_error_msg("error: '");
            put_error_char(content[count]);
            print_error_msg("' is invalid\n");
            return (84);
        }
        count += 1;
    }
        return (0);
}

int check_errors(int ac, char **av)
{
    if (ac < 2) {
        print_error_msg("error: no file given as argument\n");
        return (84);
    }
    if (file_exists(av[1]) == 84)
        return (84);
    if (content_valid(av[1]) == 84)
        return (84);
    return (0);
}
