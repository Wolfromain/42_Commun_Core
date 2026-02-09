/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:32:53 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/28 10:26:19 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	think(t_philo *philo, bool pre_simulation)
{
	long	time_to_think;
	long	time_to_eat;
	long	time_to_sleep;

	if (!pre_simulation)
		write_action(THINK, philo, 0);
	if (philo->global_philo->nbr_philo % 2 == 0)
		return ;
	time_to_eat = philo->global_philo->time_to_eat;
	time_to_sleep = philo->global_philo->time_to_sleep;
	time_to_think = time_to_eat * 2 - time_to_sleep;
	if (time_to_think < 0)
		time_to_think = 0;
	precise_usleep(time_to_think * 0.42, philo->global_philo);
}

void	*alone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->global_philo);
	set_long(&philo->philo_mutex, &philo->last_eat_time, gettime(MILLISECOND));
	increase_long(&philo->global_philo->table_mutex,
		&philo->global_philo->threads_running_nbr);
	write_action(TAKE_FIRST_FORK, philo, 0);
	while (!end_simulation(philo->global_philo))
		usleep(200);
	return (NULL);
}

void	eat(t_philo *philo)
{
	mutex_handled(&philo->first_fork->fork, LOCK);
	write_action(TAKE_FIRST_FORK, philo, 0);
	mutex_handled(&philo->second_fork->fork, LOCK);
	write_action(TAKE_SECOND_FORK, philo, 0);
	set_long(&philo->philo_mutex, &philo->last_eat_time, gettime(MILLISECOND));
	philo->eat_counter++;
	write_action(EAT, philo, 0);
	precise_usleep(philo->global_philo->time_to_eat, philo->global_philo);
	if (philo->global_philo->limit_eat > 0
		&& philo->eat_counter == philo->global_philo->limit_eat)
		set_bool(&philo->philo_mutex, &philo->full_eat, true);
	mutex_handled(&philo->first_fork->fork, UNLOCK);
	mutex_handled(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->global_philo);
	set_long(&philo->philo_mutex, &philo->last_eat_time, gettime(MILLISECOND));
	increase_long(&philo->global_philo->table_mutex,
		&philo->global_philo->threads_running_nbr);
	desynchronize_philo(philo);
	while (!end_simulation(philo->global_philo))
	{
		if (philo->full_eat)
			break ;
		eat(philo);
		write_action(SLEEP, philo, 0);
		precise_usleep(philo->global_philo->time_to_sleep, philo->global_philo);
		think(philo, false);
	}
	return (NULL);
}

void	dinner_start(t_global *global)
{
	int	i;

	i = -1;
	if (global->limit_eat == 0)
		return ;
	else if (global->nbr_philo == 1)
		thread_handled(&global->philos[0].thread_index, alone_philo,
			&global->philos[0], CREATE);
	else
	{
		while (++i < global->nbr_philo)
			thread_handled(&global->philos[i].thread_index, dinner_simulation,
				&global->philos[i], CREATE);
	}
	thread_handled(&global->checkeur, checkeur_dinner, global, CREATE);
	global->start_diner = gettime(MILLISECOND);
	set_bool(&global->table_mutex, &global->all_thread_ready, true);
	i = -1;
	while (++i < global->nbr_philo)
		thread_handled(&global->philos[i].thread_index, NULL, NULL, JOIN);
	set_bool(&global->table_mutex, &global->stop_diner, true);
	thread_handled(&global->checkeur, NULL, NULL, JOIN);
}
