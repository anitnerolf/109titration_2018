/*
** EPITECH PROJECT, 2019
** fghj
** File description:
** hjk
*/

#include "my.h"

void    print_d(double **ar)
{
    int i = 0;
    int j = 0;

    while (ar[i] != NULL) {
        while (ar[i][j]) {
            printf("%f", ar[i][j]);
            j++;
        }
        printf("\n");
        i++;
        j = 0;
    }
}

double	**char_to_double(char **str, char *buffer, char **ptr)
{
    int i = count_words(buffer, '\n');
    double **d = NULL;
    int j = 0;
    char *a = NULL;
    char *b = NULL;

    if ((d = malloc(sizeof(double *) * (i + 1))) == NULL)
        return (NULL);
    for (j = 0; j < i; j++) {
        if ((d[j] = malloc(sizeof(double) * 1)) == NULL)
            return (NULL);
        ptr = &str[j];
        a = strsep(ptr, ";");
        d[j][0] = atof(a);
        b = strsep(ptr, ";");
        d[j][1] = atof(b);
    }
    return (d);
}

double	cal_deriv(double a, double b, double c, double d)
{
    return ((a - b) / (c - d));
}

double	**first_derivative(double **d, char *buffer, int g)
{
    int i = count_words(buffer, '\n');
    double **f = NULL;
    int k = 1;

    if ((f = malloc(sizeof(double *) * i)) == NULL)
        return (NULL);
    for (int j = 0 ; j < i - g; j++) {
        if ((f[j] = malloc(sizeof(double) * 2)) == NULL)
            return (NULL);
        f[j][0] = d[k][0];
        f[j][1] = cal_deriv(d[k + 1][1], d[k - 1][1], d[k + 1][0], d[k - 1][0]);
        k++;
    }
    return (f);
}

double	find_equivalent_point(double **f, char *buffer)
{
    int i = count_words(buffer, '\n') - 2;
    int j = 0;
    int k;
    double m = 0;
    double t = 0;

    for (j = 0; j < i; j++) {
        if (f[j][1] > m) {
            k = j;
            m = f[k][1];
        }
    }
    t = f[k][0];
    return (t);
}
