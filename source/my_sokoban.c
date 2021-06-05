/*
** EPITECH PROJECT, 2021
** my_sokoban.c
** File description:
** main function for my_sokoban
*/

#include "sokoban.h"

static void init_sokoban(char *content)
{
    static int copied = 0;

    initscr();
    noecho();
}

void replay_sokoban(const char *title, char *content)
{
    endwin();
    free(content);
    my_sokoban(title);
}

int end_of_game(char *content, const char *title, int *locations,
int *return_value)
{
    if (game_won(content, locations)) {
        clear();
        printw(content);
        refresh();
        endwin();
        return_value[0] = 0;
    }
    else if (game_lost(content)) {
        clear();
        printw(content);
        refresh();
        endwin();
        return_value[0] = 1;
    }
    else {
        return_value[0] = -1;
    }
    return (return_value[0]);
}

int my_sokoban(const char *title)
{
    int key = -1;
    char *content = (read_file(title));
    int *locations = NULL;
    int *return_value = malloc(sizeof(int));

    content = adjust_map(content);
    locations = stock_o(content);
    init_sokoban(content);
    while (key != ' ') {
        enlarge(content);
        clear();
        printw(content);
        refresh();
        key = getch();
        if (key != ' ')
            content = move_player(key, content, locations);
        if (end_of_game(content, title, locations, return_value) != -1)
            return (return_value[0]);
    }
    replay_sokoban(title, content);
}
