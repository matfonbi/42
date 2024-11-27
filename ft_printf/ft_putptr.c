/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_fonbonn <m_fonbonn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:59:55 by m_fonbonn         #+#    #+#             */
/*   Updated: 2024/11/27 14:07:48 by m_fonbonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_count(unsigned long num, int *count)
{
	char	*hex_digits;

	if (num == 0)
	{
		ft_putstr_count("(nil)", count);
		return ;
	}
	hex_digits = "0123456789abcdef";
	if (num >= 16)
		ft_putptr_count(num / 16, count);
	ft_putchar_count(hex_digits[num % 16], count);
}
