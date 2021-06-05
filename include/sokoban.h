/*
** EPITECH PROJECT, 2020
** my_sokoban.h
** File description:
** header
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <ncurses.h>
#include <curses.h>

int my_putstr(char const *str);
int my_getnbr(char const *str);
long long get_lglg(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_revstr(char *str);
int print_error_msg(char const *str);
void put_error_char(char c);

int check_errors(int ac, char **av);
void display_usage(void);
int my_sokoban(const char *string);
char *read_file(const char *title);
int get_nb_columns(char *content);
int get_nb_lines(char *content);
int enlarge(char *content);
int copy_initial_map(char *content);
char *move_player(int key, char *content, int *locations);
char *move_space(char movement, char *map, int *locations);
char *move_crate(char movement, char *map, int *locations);
int find_player(char *content);
int find_line_len(char *map);
void reset_file(const char *title);
char find_next_pos(int cursor_player, char movement, char *map);
int is_o(int cursor_searched, int *locations);
int *stock_o(char *map);
int game_won(char *map, int *locations);
int game_lost(char *map);
char *adjust_map(char *map);