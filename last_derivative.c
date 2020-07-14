/*
** EPITECH PROJECT, 2019
** fghj
** File description:
** hjk
*/

#include "my.h"


double	calc_two(double **d, int k, int a)
{
    return ((d[k][1] - d[k - 1][1]) / ((d[k][0] - d[k - 1][0]) * a));
}

double	calc_three(double **d, int k, int a)
{
    return ((d[k + 1][1] - d[k][1]) / ((d[k + 1][0] - d[k][0]) * a));
}

double	**last_derivative(double **d, double t, tr_t *p)
{
    double	**g = NULL;

    if ((g = malloc(sizeof(double *) * t)) == NULL)
        return (NULL);
    for (; p->i != t; p->i++, p->w = p->w + 0.1) {
        if ((g[p->i] = malloc(sizeof(double) * 2)) == NULL)
            return (NULL);
        g[p->i][0] = p->w;
    }
    p->f = calc_two(d, p->r, p->ten);
    g[0][1] = d[p->r - 1][1];
    p->j = g[0][0];
    for (p->i = 1 ; p->j < d[p->r][0] - 0.1; p->j = p->j + 0.1, p->i++) {
        g[p->i][1] = g[p->i - 1][1] + p->f;
    }
    p->f = calc_three(d, p->r, p->ten);
    for ( ; p->j < d[p->r + 1][0] - 0.1; p->j = p->j + 0.1, p->i++) {
        g[p->i][1] = g[p->i - 1][1] + p->f;
    }
    return (g);
}

void	print_last_derivative(tr_t *t)
{
    int i = 0;

    printf("\nSecond derivative estimated:\n");
    while (i != t->e) {
        printf("%.1f ml -> %.2f\n", t->ld[i][0], t->ld[i][1]);
        i++;
    }
    printf("\n");
}

double	last_point(tr_t *t)
{
    int	i = 0;

    for (i = 0; i != t->e; i++) {
        if (t->ld[i][1] * t->ld[i + 1][1] < 0)
            return (t->ld[i][0]);
    }
    return (0);
}
