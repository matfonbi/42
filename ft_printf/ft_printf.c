/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_fonbonn <m_fonbonn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:58:51 by m_fonbonn         #+#    #+#             */
/*   Updated: 2024/11/27 14:09:02 by m_fonbonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void	tout_print(va_list args, char c, int *count);

void	print_ptr(void *ptr, int *count);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tout_print(args, str[i + 1], &count);
			i += 2;
		}
		else
		{
			ft_putchar_count(str[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}

void	tout_print(va_list args, char c, int *count)
{
	void	*ptr;

	if (c == 'c')
		ft_putchar_count(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr_count(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_count(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned_count(va_arg(args, unsigned int), count);
	else if (c == 'x')
		hec_to_hex_min(va_arg(args, int), count);
	else if (c == 'X')
		hec_to_hex_max(va_arg(args, int), count);
	else if (c == 'p')
	{
		ptr = va_arg(args, void *);
		print_ptr(ptr, count);
	}
	else if (c == '%')
		ft_putchar_count('%', count);
}

void	print_ptr(void *ptr, int *count)
{
	if (ptr == NULL)
		ft_putstr_count("(nil)", count);
	else
	{
		ft_putstr_count("0x", count);
		ft_putptr_count((unsigned long)ptr, count);
	}
}
/*
   int main(void)
   {
   ft_printf("%p", 16);
   }*/
