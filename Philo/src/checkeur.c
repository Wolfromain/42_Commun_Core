/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:49:09 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/28 11:45:40 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	philo_died(t_philo *philo)
{
	long	elapse;
	long	time_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full_eat))
		return (false);
	elapse = gettime(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_eat_time);
	time_to_die = philo->global_philo->time_to_die / 1e3;
	if (elapse > time_to_die)
		return (true);
	return (false);
}

void	*checkeur_dinner(void *data_monitor)
{
	t_global	*data;
	int			i;

	data = (t_global *)data_monitor;
	while (!all_threads_running(&data->table_mutex, &data->threads_running_nbr,
			data->nbr_philo))
		usleep(1);
	while (!end_simulation(data))
	{
		i = -1;
		while (++i < data->nbr_philo && !end_simulation(data))
		{
			if (philo_died(data->philos + i))
			{
				set_bool(&data->table_mutex, &data->stop_diner, true);
				write_action(DIED, data->philos + i, 0);
			}
		}
	}
	return (NULL);
}
