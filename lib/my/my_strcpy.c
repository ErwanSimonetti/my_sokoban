/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy a string into an other
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;
    int y;
    int z;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    z = 0;
    while (dest[z] != '\0') {
        z += 1;
    }
    if (z > i) {
        while (z != i) {
            dest[z - 1] = dest[z];
            z -= 1;
        }
    }
    return (dest);
}
