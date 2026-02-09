/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:59:27 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/26 12:50:44 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	gettime(t_time time_code)
{
	struct timeval	time_value;

	gettimeofday(&time_value, NULL);
	if (time_code == SECOND)
		return (time_value.tv_sec + (time_value.tv_usec / 1e6));
	else if (time_code == MILLISECOND)
		return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
	else if (time_code == MICROSECOND)
		return ((time_value.tv_sec * 1e6) + time_value.tv_usec);
	return (1337);
}

void	precise_usleep(long usec, t_global *global)
{
	long	start;
	long	elapsed;
	long	remaining_time;

	start = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start < usec)
	{
		if (end_simulation(global))
			break ;
		elapsed = gettime(MICROSECOND) - start;
		remaining_time = usec - elapsed;
		if (remaining_time > 1000)
			usleep(remaining_time / 2);
		else
			while (gettime(MICROSECOND) - start < usec)
				;
	}
}
