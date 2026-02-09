/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:55:23 by rbouquet          #+#    #+#             */
/*   Updated: 2024/09/18 10:37:49 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_stack **a, t_stack **b,
				t_stack *smallest_node, int reverse)
{
	while (*a != smallest_node->target_node && *b != smallest_node)
	{
		if (reverse == 1)
			rr(a, b);
		else
			rrr(a, b);
		set_index(*a);
		set_index(*b);
	}
}

void	stop_rotation(t_stack **stack, t_stack *smallest_node, char name)
{
	while (*stack != smallest_node)
	{
		if (name == 'a')
		{
			if (smallest_node->index <= stack_len(*stack) / 2)
				ra(stack);
			else
				rra(stack);
		}
		if (name == 'b')
		{
			if (smallest_node->index <= stack_len(*stack) / 2)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;
	int		reverse;

	reverse = 0;
	smallest_node = find_lowest_cost(*b);
	if ((smallest_node->index <= stack_len(*b) / 2)
		&& (smallest_node->target_node->index <= stack_len(*a) / 2))
	{
		reverse = 1;
		rotation(a, b, smallest_node, reverse);
	}
	else if ((smallest_node->index > stack_len(*b) / 2)
		&& (smallest_node->target_node->index > stack_len(*a) / 2))
	{
		reverse = 0;
		rotation(a, b, smallest_node, reverse);
	}
	stop_rotation(b, smallest_node, 'b');
	stop_rotation(a, smallest_node->target_node, 'a');
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;
	int		len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		stack_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(a, b);
	}
	little_sort(a);
	while (*b)
	{
		init_node(*a, *b);
		sort(a, b);
	}
	set_index(*a);
	smallest_node = stack_min(*a);
	if (smallest_node->index <= stack_len(*a) / 2)
		while (*a != smallest_node)
			ra(a);
	else
		while (*a != smallest_node)
			rra(a);
}
