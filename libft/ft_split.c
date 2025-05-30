/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:02:29 by mfonbonn          #+#    #+#             */
/*   Updated: 2024/11/26 18:33:12 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_is_separator(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i + 1], sep) == 1
			&& char_is_separator(str[i], sep) == 0)
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *from, char sep)
{
	int	i;

	i = 0;
	while (char_is_separator(from[i], sep) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

int	write_split(char **split, char *str, char sep, int i)
{
	int		j;
	int		word;

	word = -1;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i], sep) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_separator(str[i + j], sep) == 0)
				j++;
			split[++word] = (char *)malloc(sizeof (char) * (j + 1));
			if (split[word] == NULL)
			{
				while (word--)
					free(split[word]);
				return (0);
			}
			write_word(split[word], str + i, sep);
			i += j;
		}
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	char	*str;
	int		words;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	if (write_split(res, str, c, i) == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
