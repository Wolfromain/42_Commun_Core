/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:59:51 by rbouquet          #+#    #+#             */
/*   Updated: 2024/09/23 11:34:13 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *stack, int nbr)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_error(t_stack **stack, char **argv, int arg_2)
{
	free_stack(*stack);
	if (arg_2 == 0)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_stack		*tmp;
	t_stack		*cur;

	if (stack == NULL)
		return ;
	cur = stack;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}

int	syntaxe_error(char *nbr)
{
	int	i;

	i = 0;
	if (!(nbr[i] == '+' || nbr[i] == '-' || (nbr[i] >= '0' && nbr[i] <= '9')))
		return (1);
	if ((nbr[i] == '+' || nbr[i] == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (1);
	while (nbr[++i])
	{	
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (1);
	}
	return (0);
}
