/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:05:07 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/28 10:26:03 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	clean(t_global *global)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < global->nbr_philo)
	{
		philo = global->philos + i;
		mutex_handled(&philo->philo_mutex, DESTROY);
	}
	mutex_handled(&global->write_mutex, DESTROY);
	mutex_handled(&global->table_mutex, DESTROY);
	free(global->forks);
	free(global->philos);
}

void	wait_all_threads(t_global *global)
{
	while (!get_bool(&global->table_mutex, &global->all_thread_ready))
		usleep(1);
}

bool	all_threads_running(t_mtx *mutex, long *threads, long nbr_philo)
{
	bool	check;

	check = false;
	mutex_handled(mutex, LOCK);
	if (*threads == nbr_philo)
		check = true;
	mutex_handled(mutex, UNLOCK);
	return (check);
}

void	increase_long(t_mtx *mutex, long *value)
{
	mutex_handled(mutex, LOCK);
	(*value)++;
	mutex_handled(mutex, UNLOCK);
}

void	desynchronize_philo(t_philo *philo)
{
	if (philo->global_philo->nbr_philo % 2 == 0)
	{
		if (philo->philo_index % 2 == 0)
			precise_usleep(3e4, philo->global_philo);
	}
	else
	{
		if (philo->philo_index % 2 == 1)
			think(philo, true);
	}
}
