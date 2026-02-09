/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:17:38 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/30 09:23:37 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	arg_init(t_global *global, char **argv)
{
	global->nbr_philo = ft_atol(argv[1]);
	global->time_to_die = ft_atol(argv[2]) * 1000;
	global->time_to_eat = ft_atol(argv[3]) * 1000;
	global->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (global->time_to_die < 60000 || global->time_to_eat < 60000
		|| global->time_to_sleep < 60000)
	{
		printf("Philosophers need more time to eat / sleep or think\n");
		printf("More than 60ms\n");
		return (-1);
	}
	else if (global->nbr_philo < 1)
		return (printf("Wrong number of philosopher\n"));
	if (argv[5])
	{
		global->limit_eat = ft_atol(argv[5]);
		if (global->limit_eat == -1)
			return (-1);
	}
	else
		global->limit_eat = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_global	global;

	if ((argc == 5) || (argc == 6))
	{
		if (arg_init(&global, argv) == -1)
			return (-1);
		if (init_global(&global) == -1)
			return (clean(&global), -1);
		dinner_start(&global);
		clean(&global);
	}
	else
	{
		printf("Wrong intput\n");
		return (printf("Try for exemple ./philo 5 800 200 200 [5]\n"), -1);
	}
	return (0);
}
