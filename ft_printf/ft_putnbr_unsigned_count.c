/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_count.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_fonbonn <m_fonbonn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:59:43 by m_fonbonn         #+#    #+#             */
/*   Updated: 2024/11/26 13:59:45 by m_fonbonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr_unsigned_count(unsigned int n, int *fd)
{
	if (n < 10)
		ft_putchar_count(n + 48, fd);
	else
	{
		ft_putnbr_count(n / 10, fd);
		ft_putchar_count(n % 10 + 48, fd);
	}
}
