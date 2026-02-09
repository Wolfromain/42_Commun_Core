/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:06:37 by rbouquet          #+#    #+#             */
/*   Updated: 2024/09/02 09:38:05 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*before_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

void	stack_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		init_node(*a, *b);
		stop_rotation(a, stack_min(*a), 'a');
		pb(a, b);
	}
}

t_stack	*find_lowest_cost(t_stack *stack)
{
	long	min_cost;
	t_stack	*lowest_cost;

	if (stack == NULL)
		return (NULL);
	min_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			lowest_cost = stack;
		}
		stack = stack->next;
	}
	return (lowest_cost);
}
