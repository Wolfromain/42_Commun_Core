/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:00:35 by rbouquet          #+#    #+#             */
/*   Updated: 2024/09/23 11:31:13 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *argv)
{
	int		i;
	long	signe;
	long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32)
		i++;
	if (argv[i] == '+')
		i++;
	else if (argv[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		nb = (nb * 10) + (argv[i] - '0');
		i++;
	}
	return (nb * signe);
}

void	init_stack_a(t_stack **stack_a, char **argv, int argc)
{
	long	nbr;
	int		i;
	int		arg_2;

	arg_2 = 1;
	if (argc == 2)
		arg_2 = 0;
	i = 0;
	while (argv[i])
	{
		if (syntaxe_error(argv[i]))
			free_error(stack_a, argv, arg_2);
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			free_error(stack_a, argv, arg_2);
		if (check_duplicate(*stack_a, (int)nbr) == 1)
			free_error(stack_a, argv, arg_2);
		stack_add_node(stack_a, (int)nbr);
		i++;
	}
}
