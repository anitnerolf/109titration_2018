/*
** EPITECH PROJECT, 2019
** 109titration
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stddef.h>

typedef	struct	tr
{
    char	*buffer1;
    double	**fd;
    double	**sd;
    double	**ld;
    double	**d;
    int	k;
    double	p;
    double	sp;
    char	**z;
    char	**y;
    int	c;
    int	r;
    int	ten;
    double	e;
    double	w;
    double	f;
    double	j;
    int	i;
}	tr_t;

void	usage_h(void);
int	main(int ac, char **av);
char	*read_file(char *str);
tr_t	*main_struct(char **av);
int	check_map(char **str);
int	check_if_number(char *str);
int	count_words(char *, char);
char	**double_array(char *, char);
double	**char_to_double(char **, char *, char **);
double	**first_derivative(double **, char *, int);
double	**second_derivative(double **, char *);
double	**last_derivative(double **, double, tr_t *);
void	my_show_word_array(char **);
double	find_equivalent_point(double **, char *);
double	find_equivalent_point2(double **, char *);
double	cal_deriv(double, double, double, double);
int	count_nb(double **, double);
double	calc_ten(double **, int, int);
void	print_last_derivative(tr_t *);
void	print_first_derivative(double **, int, int);
double	last_point(tr_t *);
void	short_three(tr_t *);
int	check_array(double **);
void	free_struct(tr_t *);
int	main(int, char **);
void	free_double(double **);
void	free_char(char **);

#endif /* MY_H_ */
