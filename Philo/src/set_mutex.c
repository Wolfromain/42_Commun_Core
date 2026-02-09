/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:45:59 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/26 14:40:57 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	mutex_handled(mutex, LOCK);
	*dest = value;
	mutex_handled(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	result;

	mutex_handled(mutex, LOCK);
	result = *value;
	mutex_handled(mutex, UNLOCK);
	return (result);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	mutex_handled(mutex, LOCK);
	*dest = value;
	mutex_handled(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	result;

	mutex_handled(mutex, LOCK);
	result = *value;
	mutex_handled(mutex, UNLOCK);
	return (result);
}

bool	end_simulation(t_global *global)
{
	return (get_bool(&global->table_mutex, &global->stop_diner));
}
