/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:18:40 by mfonbonn          #+#    #+#             */
/*   Updated: 2024/11/22 11:20:05 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*out;

	if (!s || !f)
		return (NULL);
	out = malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
/*
   char my_function(unsigned int i, char c)
   {
   return (c + i); 
   }

   int main(void)
   {
   char const *str = "abcdef";
   char *result = ft_strmapi(str, my_function);
   printf("%s\n", result);
   }*/
