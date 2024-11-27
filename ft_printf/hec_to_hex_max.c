/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hec_to_hex_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_fonbonn <m_fonbonn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:00:38 by m_fonbonn         #+#    #+#             */
/*   Updated: 2024/11/26 14:08:51 by m_fonbonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	hec_to_hex_max(int nbr, int *count)
{
	int				i;
	unsigned int	num;
	char			*base;
	char			buffer[32];

	base = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int)nbr;
	if (num == 0)
	{
		ft_putchar_count('0', count);
		return ;
	}
	while (num > 0)
	{
		buffer[i++] = base[num % 16];
		num /= 16;
	}
	while (i > 0)
	{
		ft_putchar_count(buffer[--i], count);
	}
}
