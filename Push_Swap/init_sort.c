/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:02:13 by rbouquet          #+#    #+#             */
/*   Updated: 2024/08/31 16:38:03 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_best_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*cur_stack_a;
	t_stack	*best_node;
	long	best_index;

	while (stack_b)
	{
		best_index = LONG_MAX;
		cur_stack_a = stack_a;
		while (cur_stack_a)
		{
			if (cur_stack_a->value > stack_b->value
				&& cur_stack_a->value < best_index)
			{
				best_index = cur_stack_a->value;
				best_node = cur_stack_a;
			}
			cur_stack_a = cur_stack_a->next;
		}
		if (best_index == LONG_MAX)
			stack_b->target_node = stack_min(stack_a);
		else
			stack_b->target_node = best_node;
		stack_b = stack_b->next;
	}
}

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->index;
		if (stack_b->index > len_b / 2)
			stack_b->push_cost = len_b - stack_b->index;
		if (stack_b->target_node->index <= len_a / 2)
			stack_b->push_cost += stack_b->target_node->index;
		else
			stack_b->push_cost += len_a - stack_b->target_node->index;
		stack_b = stack_b->next;
	}
}

void	set_index(t_stack *stack)
{
	int	pos;

	pos = 0;
	if (stack == NULL)
		return ;
	while (stack)
	{
		stack->index = pos;
		stack = stack->next;
		pos++;
	}
}

void	init_node(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	target_best_node(a, b);
	set_cost(a, b);
}
