/*
** EPITECH PROJECT, 2020
** get_long_long.c
** File description:
** get long long from string
*/

long long get_dozen(char const *str)
{
    long long count = 1;
    long long dozen = 1;

    if (str[0] == '-')
        count += 1;
    while (str[count] != '\0') {
        dozen *= 10;
        count += 1;
    }
    return (dozen);
}

int get_neg(char const *str)
{
    if (str[0] == '-')
        return (1);
    else
        return (-1);
}

long long get_lglg(char const *str)
{
    long long dozen = get_dozen(str);
    long long cursor = 0;
    int is_neg = get_neg(str);
    long long nb = 0;

    if (is_neg == 1)
        cursor += 1;
    while (str[cursor] != '\0') {
        nb += (str[cursor] - '0') * dozen;
        dozen /= 10;
        cursor += 1;
    }
    if (is_neg == 1)
        nb *= -1;
    return (nb);
}
