/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:58:52 by mfonbonn          #+#    #+#             */
/*   Updated: 2025/05/14 17:58:55 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*between(char *str, char c, int index)
{
	char	*word;
	int		start;
	int		j;
	int		tmp;

	start = index;
	tmp = ft_strlen(str);
	while (str[index] != c && index < tmp)
		index++;
	if (index == start)
		return (NULL);
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (start < index)
	{
		word[j] = str[start];
		j++;
		start++;
	}
	word[j] = '\0';
	return (word);
}

static char	**make(char **res, char *s, char c, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && j <= len)
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = between(s, c, i);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len;

	len = count_word((char *)s, c);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res = make(res, (char *)s, c, len);
	return (res);
}
