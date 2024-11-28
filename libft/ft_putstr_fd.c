/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:16:07 by mfonbonn          #+#    #+#             */
/*   Updated: 2024/11/22 11:16:29 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
int main(void)
{
	ft_putstr_fd("Standar", 1); 
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Erreur", 2);
	ft_putchar_fd('\n', 2);
	return (0);
}*/
