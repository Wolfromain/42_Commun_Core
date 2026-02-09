/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:45:19 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/30 09:24:34 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	fork_for_each_philo(t_philo *philo, t_fork *forks, int index)
{
	int	philo_nbr;

	philo_nbr = philo->global_philo->nbr_philo;
	philo->first_fork = &forks[(index + 1) % philo_nbr];
	philo->second_fork = &forks[index];
	if (philo->philo_index % 2 == 0)
	{
		philo->first_fork = &forks[index];
		philo->second_fork = &forks[(index + 1) % philo_nbr];
	}
}

void	init_philo(t_global *global)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < global->nbr_philo)
	{
		philo = global->philos + i;
		philo->philo_index = i + 1;
		philo->full_eat = false;
		philo->eat_counter = 0;
		philo->global_philo = global;
		mutex_handled(&philo->philo_mutex, INIT);
		fork_for_each_philo(philo, global->forks, i);
	}
}

int	init_global(t_global *global)
{
	int	i;

	global->stop_diner = false;
	global->all_thread_ready = false;
	global->threads_running_nbr = 0;
	global->philos = malloc(sizeof(t_philo) * global->nbr_philo);
	if (global->philos == NULL)
		return (-1);
	mutex_handled(&global->table_mutex, INIT);
	mutex_handled(&global->write_mutex, INIT);
	global->forks = malloc(sizeof(t_fork) * global->nbr_philo);
	if (global->forks == NULL)
		return (-1);
	i = -1;
	while (++i < global->nbr_philo)
	{
		mutex_handled(&global->forks[i].fork, INIT);
		global->forks[i].fork_index = i;
	}
	init_philo(global);
	return (0);
}
