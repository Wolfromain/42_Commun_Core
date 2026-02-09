/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:41:26 by rbouquet          #+#    #+#             */
/*   Updated: 2024/09/16 11:13:13 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack		*min;
	int			smallest_value;

	if (stack == NULL)
		return (NULL);
	smallest_value = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest_value = stack->value;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

t_stack	*stack_max(t_stack *stack)

{
	t_stack	*max;
	int		max_value;

	if (stack == NULL)
		return (NULL);
	max_value = INT_MIN;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack	*stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->value = n;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last_node = stack_last(*stack);
		last_node->next = new_node;
	}
}
