/*
** EPITECH PROJECT, 2019
** hj
** File description:
** jk
*/

#include "my.h"

int	check_if_number(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!(str[i] <= 57 && str[i] >= 48) &&  \
    str[i] != ';' && str[i] != '\n' && str[i] != '.')
            return (-1);
        i++;
    }
    return (0);
}
