#include"get_next_line.h"

void	ft_strcat(char const *dest, char const *src, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		str[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		str[i] = src[j];
		j++;
		i++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		totalsize;

	if (!s1 || !s2) 
        return (NULL);
	totalsize = sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = malloc(totalsize);
	if (!str)
		return (NULL);
	ft_strcat(s1, s2, str);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}