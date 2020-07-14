/*
** EPITECH PROJECT, 2019
** 109titration
** File description:
** main
*/

#include "my.h"

void	print_first_derivative(double **f, int k, int g)
{
    int i = 0;

    while (i < k - g) {
        printf("%.1f ml -> %.2f\n", f[i][0], f[i][1]);
        i++;
    }
}

int	check_array(double **str)
{
    if (str == NULL)
        return (84);
    return (0);
}

int	short_two(tr_t *t)
{
    t->k = count_words(t->buffer1, '\n');
    t->z = double_array(t->buffer1, '\n');
    t->d = char_to_double(t->z, t->buffer1, t->y);
    t->fd = first_derivative(t->d, t->buffer1, 2);
    if (check_array(t->fd) == 84)
        return (84);
    printf("Derivative:\n");
    print_first_derivative(t->fd, t->k, 2);
    t->p = find_equivalent_point(t->fd, t->buffer1);
    printf("\nEquivalent point at %.1f ml\n\n", t->p);
    short_three(t);
    return (0);
}

int	short_function(tr_t *t)
{
    if (t == NULL || check_if_number(t->buffer1) == -1)
        return (84);
    else {
        return (short_two(t));
    }
}

int	main(int ac, char **av)
{
    tr_t	*t = NULL;
    int	d = 0;

    if (ac != 2)
        return (84);
    else {
        if (strcmp(av[1], "-h") == 0) {
            usage_h();
            return (0);
        } else {
            if (check_map(av) == 84)
                return (84);
            else {
                t = main_struct(av);
                t->i = short_function(t);
                d = t->i;
                return (d);
            }
        }
    }
}
