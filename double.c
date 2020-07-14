/*
** EPITECH PROJECT, 2019
** ghj
** File description:
** jk
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int     check_column(char *str, char c)
{
    int i = 0;

    for (i = 0; str[i] != '\0' && str[i] != c; i++);
    return (i);
}

int     count_words(char *str, char c)
{
    int z = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c && str[i + 1] != '\0')
            z++;
        i++;
    }
    return (z + 1);
}

char	**double_array(char *str, char c)
{
    int	i = 0;
    int	j = 0;
    int	k = 0;
    int	a = count_words(str, c);
    int	b = check_column(str, c);
    char	**arr = malloc(sizeof(char *) * (a + 1));

    for ( ; str[k] != '\0'; i++) {
        arr[i] = malloc(sizeof(char) * (b + 1));
        while (str[k] != c) {
            arr[i][j] = str[k];
            j++;
            k++;
        }
        k++;
        arr[i][j] = '\0';
        j = 0;
    }
    arr[i] = NULL;
    return (arr);
}

void	my_show_word_array(char **str)
{
    int	i = 0;

    while (str[i]) {
        printf("%s\n", str[i]);
        i++;
    }
}
