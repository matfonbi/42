/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_fonbonn <m_fonbonn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:00:07 by m_fonbonn         #+#    #+#             */
/*   Updated: 2024/11/26 14:55:35 by m_fonbonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putstr_count(char *s, int *fd)
{
	int	i;

	if (!s)
	{
		ft_putstr_count("(null)", fd);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_count(s[i], fd);
		i++;
	}
}
/*
int main(void)
{
	char c = 'c';
	char *ptr = &c;
	ft_putstr_fd(ptr, 1); 
	return (0);
}*/
