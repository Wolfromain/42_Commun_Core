/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:01:33 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/26 10:44:17 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	mutex_handled(t_mtx *mutex, t_opcode mutex_code)
{
	if (mutex_code == LOCK)
		pthread_mutex_lock(mutex);
	else if (mutex_code == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (mutex_code == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (mutex_code == DESTROY)
		pthread_mutex_destroy(mutex);
}

void	thread_handled(pthread_t *thread, void *(*foo)(void *), void *data,
		t_opcode mutex_code)
{
	if (mutex_code == CREATE)
		pthread_create(thread, NULL, foo, data);
	else if (mutex_code == JOIN)
		pthread_join(*thread, NULL);
	else if (mutex_code == DETACH)
		pthread_detach(*thread);
}
