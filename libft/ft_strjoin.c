/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:32:16 by mfonbonn          #+#    #+#             */
/*   Updated: 2024/11/22 16:53:15 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>

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

/*int	ft_gettotalsize(int size, char **strs, char *sep)
  {
  int	totalsize;
  int	i;

  totalsize = 0;
  i = 0;
  while (i < size)
  {
  totalsize += ft_strlen(strs[i]);
  totalsize += ft_strlen(sep);
  i++;
  }
  totalsize -= ft_strlen(sep);
  return (totalsize + 1);
  }*/
/*
char	*ft_error_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		totalsize;

	totalsize = sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = malloc(totalsize);
	if (!str)
		return (NULL);
	ft_strcat(s1, s2, str);
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char* strs = "lorem ipsumdol";
	printf("%s\n",  ft_strjoin(strs, "or sit amet"));
	return (0);
}*/
