/*
** EPITECH PROJECT, 2019
** jkl7gh
** File description:
** hjk
*/

#include "my.h"

tr_t	*main_struct(char **av)
{
    tr_t	*t = malloc(sizeof(tr_t));

    if (t == NULL)
        return (NULL);
    t->buffer1 = read_file(av[1]);
    t->c = 0;
    t->p = 0;
    t->fd = NULL;
    t->sd = NULL;
    t->ld = NULL;
    t->ten = 10;
    return (t);
}

void	free_double(double **d)
{
    int i = 0;

    while (d[i]) {
        free(d[i]);
        i++;
    }
    free(d);
}

void	free_char(char **d)
{
    int i = 0;

    while (d[i]) {
        free(d[i]);
        i++;
    }
    free(d);
}

void	free_struct(tr_t *t)
{
    free_double(t->fd);
    free_double(t->sd);
    free_double(t->ld);
    free_double(t->d);
    free_char(t->z);
    free(t->buffer1);
    free(t);
}

void	short_three(tr_t *t)
{
    double	x = 0;

    t->sd = first_derivative(t->fd, t->buffer1, 4);
    if (check_array(t->sd) == 84)
        exit (84);
    printf("Second derivative:\n");
    print_first_derivative(t->sd, t->k, 4);
    t->r = count_nb(t->sd, t->p);
    t->e = calc_ten(t->sd, 10, t->r);
    t->w = t->sd[t->r - 1][0];
    t->ld = last_derivative(t->sd, t->e, t);
    if (check_array(t->ld) == 84)
        exit (84);
    print_last_derivative(t);
    x = last_point(t);
    printf("Equivalent point at %.1f lm\n", x);
}

