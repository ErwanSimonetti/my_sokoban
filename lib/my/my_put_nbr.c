/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** display a number
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int rest;

    if (nb >= 0)
    {
        if (nb >= 10)
        {
            rest = (nb % 10);
            nb = (nb - rest) / 10;
            my_put_nbr(nb);
            my_putchar(rest + '0');
        }
        else
            my_putchar(48 + nb % 10);
    }
    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (-1);
        my_put_nbr(nb);
    }
}
