#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include "get_next_line.h"


char *get_next_line(int fd)
{
    static char *reste;
    char        *ligne;
    char        buffer[BUFFER_SIZE + 1];
    int         bytes_lus;

    if (!reste) // Initialiser `reste` s'il est NULL
        reste = "";
    while ((bytes_lus = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_lus] = '\0';
        reste = ft_strjoin(reste, buffer);
        if (ft_strchr(reste, '\n'))
            break;
    }
    
    if (bytes_lus < 0)
        return (NULL);
    if (!reste)
        return (NULL);
    ligne = get_line(reste);
    reste = garder_reste(reste);
    /*if (!reste || !*reste)
    {
        free(reste);
        return (NULL);
    }*/
    return(ligne);
}

char    *get_line(char *reste)
{
    int     i;
    char    *ligne;

    i = 0;
    while (reste[i] && reste[i] != '\n')
        i++;
    ligne = malloc(i + 2);
    if (!ligne)
        return (NULL);
    i = -1;
    while (reste[++i] && reste[i] != '\n')
        ligne[i] = reste[i];
    if (reste[i] == '\n')
        ligne[i++] = '\n';
    ligne[i] = '\0';
    return (ligne);
}

char    *garder_reste(char *reste)
{
    int     i, j;
    char    *new_reste;
    i = 0;
    while (reste[i] && reste[i] != '\n')
        i++;
    if (!reste[i])
    {
        free(reste);
        return (NULL);
    }
    new_reste = malloc(ft_strlen(reste) - i + 1);
    if (!new_reste)
        return (NULL);
    j = 0;
    while (reste[++i])
        new_reste[j++] = reste[i];
    new_reste[j] = '\0';
    free(reste);
    return (new_reste);
}

/*
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    printf(get_next_line(1));
}
*/

#include <fcntl.h>
#include<stdio.h>

int main()
{
    int fd = open("text.txt", O_RDONLY);
    printf(get_next_line(fd));
    printf(get_next_line(fd));
    printf(get_next_line(fd));
    printf(get_next_line(fd));
    printf(get_next_line(fd));
    printf(get_next_line(fd));
    close(fd);
    return (0);
}
