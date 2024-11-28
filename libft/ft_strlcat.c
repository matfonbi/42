/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:22:02 by mfonbonn          #+#    #+#             */
/*   Updated: 2024/11/22 11:37:54 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <unistd.h>
*/
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size == 0 || i > size)
		return (size + j);
	if (!*src)
		return (i);
	j = 0;
	while (src[j] && (i + j < size -1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int    i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int    main()
{
	char buffer[10];
    char dest[] = "Hello";
 
    strcpy(buffer, dest);
    char src[] = "Wooooooorld";
    printf("ft_strlcat : %d\n", ft_strlcat(buffer, src, 25));
    printf("strlcat : %zu\n", strlcat(buffer, src, 25));
    printf("result : %s\n", buffer);
 
    return 0;
}*/
