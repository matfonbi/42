/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:02:31 by mfonbonn          #+#    #+#             */
/*   Updated: 2025/05/14 18:02:34 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_pile **pile_a, int print)
{
	if (*pile_a && (*pile_a)->next != *pile_a)
	{
		*pile_a = (*pile_a)->next;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_pile **pile_b, int print)
{
	if (*pile_b && (*pile_b)->next != *pile_b)
	{
		*pile_b = (*pile_b)->next;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rotate_both(t_pile **p_a, t_pile **p_b)
{
	if (*p_a && (*p_a)->next != *p_a && *p_b && (*p_b)->next != *p_b)
	{
		rotate_a(p_a, 0);
		rotate_b(p_b, 0);
		write(1, "rr\n", 3);
	}
}
