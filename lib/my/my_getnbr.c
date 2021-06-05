/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get a number from a string
*/

int my_getnbr(char const *str)
{
    int result = 0;
    char sign = -1;
    int i;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++)
    {
        if (str[i] == '-')
            sign *= -1;
    }

    for (; str[i] >= '0' && str[i] <= '9'; i++)
    {
        result = result * 10 - (str[i] - '0');
    }
    result = result * sign;
    return (result);
}
