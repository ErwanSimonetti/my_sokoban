/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** give the size of a string
*/

int my_strlen(char const *str)
{
    char letter;
    int i;

    i = 0;
    letter = '0';
    while (letter != '\0') {
        letter = str[i + 1];
        i += 1;
    }
    return (i);
}
