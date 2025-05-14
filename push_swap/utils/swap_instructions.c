/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonbonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:02:44 by mfonbonn          #+#    #+#             */
/*   Updated: 2025/05/14 18:02:48 by mfonbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_pile **pile_a)
{
	int	tmp;

	tmp = (*pile_a)->value;
	(*pile_a)->value = (*pile_a)->next->value;
	(*pile_a)->next->value = tmp;
	write(1, "sa\n", 3);
}

// void	swap_b(t_pile **pile_b)
// {
// 	int	tmp;

// 	tmp = (*pile_b)->value;
// 	(*pile_b)->value = (*pile_b)->next->value;
// 	(*pile_b)->next->value = tmp;
// 	write(1, "sb\n", 3);
// }
