/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_philo_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:33:57 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/28 10:44:20 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_action_debug(t_philo_action action, t_philo *philo, long elapsed)
{
	if (action == TAKE_FIRST_FORK && !end_simulation(philo->global_philo))
		printf("%-6ld %d has taken the first fork (id : %d)\n", elapsed,
			philo->philo_index, philo->first_fork->fork_index);
	else if (action == TAKE_SECOND_FORK && !end_simulation(philo->global_philo))
		printf("%-6ld %d has taken the second fork (id : %d)\n", elapsed,
			philo->philo_index, philo->second_fork->fork_index);
	else if (action == EAT && !end_simulation(philo->global_philo))
		printf("%-6ld %d is eating (meal nb : %ld)\n", elapsed,
			philo->philo_index, philo->eat_counter);
	else if (action == SLEEP && !end_simulation(philo->global_philo))
		printf("%-6ld %d is sleeping\n", elapsed, philo->philo_index);
	else if (action == THINK && !end_simulation(philo->global_philo))
		printf("%-6ld %d is thinking\n", elapsed, philo->philo_index);
	else if (action == DIED)
		printf("%-6ld %d died\n", elapsed, philo->philo_index);
}

void	write_action(t_philo_action action, t_philo *philo, bool debug)
{
	long	elapsed;

	if (philo->full_eat)
		return ;
	elapsed = gettime(MILLISECOND) - philo->global_philo->start_diner;
	mutex_handled(&philo->global_philo->write_mutex, LOCK);
	if (debug)
		write_action_debug(action, philo, elapsed);
	else
	{
		if ((action == TAKE_FIRST_FORK || action == TAKE_SECOND_FORK)
			&& !end_simulation(philo->global_philo))
			printf("%-6ld philo %d has taken a fork\n", elapsed,
				philo->philo_index);
		else if (action == EAT && !end_simulation(philo->global_philo))
			printf("%-6ld philo %d is eating\n", elapsed, philo->philo_index);
		else if (action == SLEEP && !end_simulation(philo->global_philo))
			printf("%-6ld philo %d is sleeping\n", elapsed, philo->philo_index);
		else if (action == THINK && !end_simulation(philo->global_philo))
			printf("%-6ld philo %d is thinking\n", elapsed, philo->philo_index);
		else if (action == DIED)
			printf("%-6ld philo %d is die\n", elapsed, philo->philo_index);
	}
	mutex_handled(&philo->global_philo->write_mutex, UNLOCK);
}
