/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_fonbonn <m_fonbonn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:59:09 by m_fonbonn         #+#    #+#             */
/*   Updated: 2024/11/26 13:59:12 by m_fonbonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
