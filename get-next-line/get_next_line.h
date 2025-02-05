#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd);
char    *garder_reste(char *reste);
char    *get_line(char *reste);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strcat(char const *dest, char const *src, char *str);
char *ft_strchr(const char *s, int c);

#endif
