/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_fonbonn <m_fonbonn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:59:28 by m_fonbonn         #+#    #+#             */
/*   Updated: 2024/11/26 13:59:30 by m_fonbonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr_count(int n, int *fd)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*fd) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_count('-', fd);
		n = -n;
	}
	if (n < 10)
		ft_putchar_count(n + 48, fd);
	else
	{
		ft_putnbr_count(n / 10, fd);
		ft_putchar_count(n % 10 + 48, fd);
	}
}
/*
int main(void)
{
	ft_putnbr_fd(-2147483648, 1); 
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}*/
