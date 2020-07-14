/*
** EPITECH PROJECT, 2018
** CPE_duostumper_2_2018
** File description:
** stumper
*/

#include "my.h"

int	file_size(char *filepath)
{
    int	size = 0;
    struct	stat	st;

    stat(filepath, &st);
    size = st.st_size;
    return (size);
}

char	*read_file(char *filepath)
{
    int	fd = 0;
    int	size = file_size(filepath);
    char	*buffer = malloc(sizeof(char) * (size + 1));

    if (buffer == NULL)
        return (NULL);
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (NULL);
    if (size == 0)
        return (NULL);
    read(fd, buffer, size);
    close(fd);
    buffer[size + 1] = '\0';
    return (buffer);
}

int	count_nb(double **d, double k)
{
    int	i = 0;

    while (d[i][0] != k)
        i++;
    return (i);
}

double	calc_ten(double **d, int t, int j)
{
    double z = d[j + 1][0] - d[j - 1][0];

    return (z * t + 1);
}
