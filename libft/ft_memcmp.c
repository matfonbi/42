/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:30:58 by mfonbonn          #+#    #+#             */
/*   Updated: 2024/11/12 14:44:55 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int					i;
	const unsigned char	*str2;
	const unsigned char	*str1;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char *s1 = "SalUt comment ca va ?";
	char *s2 = "Salut comment ca va ?";
	int n = 22;

	printf("%d\n", memcmp(s1, s2, n));
	printf("%d", ft_memcmp(s1, s2, n));
}*/
