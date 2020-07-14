/*
** EPITECH PROJECT, 2019
** print
** File description:
** usage
*/

#include "my.h"

int	check_map(char **av)
{
    if (strcmp(av[1], "values.csv") != 0)
        return (84);
    return (0);
}

void	usage_h(void)
{
    printf("USAGE\n\t./109titration file\n");
    printf("\n\nDESCRIPTION\n\tfile\t");
    printf("a csv file containing ");
    printf("%c", '"');
    printf("vol;ph");
    printf("%c", '"');
    printf(" lines\n");
}
