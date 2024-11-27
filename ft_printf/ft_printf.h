/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_fonbonn <m_fonbonn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:03:01 by m_fonbonn         #+#    #+#             */
/*   Updated: 2024/11/26 14:05:21 by m_fonbonn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_count(char c, int *count);
void	ft_putnbr_count(int n, int *fd);
void	ft_putnbr_unsigned_count(unsigned int n, int *fd);
void	ft_putptr_count(unsigned long num, int *count);
void	ft_putstr_count(char *s, int *fd);
char	**tab_str(const char *s, char c);
void	hec_to_hex_max(int nbr, int *count);
void	hec_to_hex_min(int nbr, int *count);

#endif
