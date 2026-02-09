/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:38:07 by rbouquet          #+#    #+#             */
/*   Updated: 2024/12/28 12:33:01 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;

typedef struct s_global	t_global;

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_index;
}						t_fork;

typedef struct s_philo
{
	int					philo_index;
	long				eat_counter;
	bool				full_eat;
	long				last_eat_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_index;
	t_mtx				philo_mutex;
	t_global			*global_philo;
}						t_philo;

typedef struct s_global
{
	long				nbr_philo;
	long				time_to_eat;
	long				time_to_sleep;
	long				time_to_die;
	long				limit_eat;
	long				start_diner;
	bool				stop_diner;
	bool				all_thread_ready;
	long				threads_running_nbr;
	t_fork				*forks;
	t_mtx				table_mutex;
	t_mtx				write_mutex;
	t_philo				*philos;
	pthread_t			checkeur;
}						t_global;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef enum e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_time;

typedef enum e_action
{
	EAT,
	SLEEP,
	THINK,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_action;

// CHECKEUR.c
bool					philo_died(t_philo *philo);
void					*checkeur_dinner(void *data_monitor);

// DINER.c
void					think(t_philo *philo, bool pre_simulation);
void					eat(t_philo *philo);
void					*dinner_simulation(void *data);
void					dinner_start(t_global *global);

// FT_ATOL.c
bool					is_digit(char c);
bool					is_space(char c);
const char				*valid_input(const char *str);
long					ft_atol(const char *str);

// INIT_GLOBAL.c
void					fork_for_each_philo(t_philo *philo, t_fork *forks,
							int index);
void					init_philo(t_global *global);
int						init_global(t_global *global);

// MAIN.c
int						arg_init(t_global *global, char **argv);
int						main(int argc, char **argv);

// MUTEX.c
void					mutex_handled(t_mtx *mutex, t_opcode mutex_code);
void					thread_handled(pthread_t *thread, void *(*foo)(void *),
							void *data, t_opcode mutex_code);

// SET_MUTEX.c
void					set_bool(t_mtx *mutex, bool *dest, bool value);
bool					get_bool(t_mtx *mutex, bool *value);
void					set_long(t_mtx *mutex, long *dest, long value);
long					get_long(t_mtx *mutex, long *value);
bool					end_simulation(t_global *global);

// SET_TIME.c
long					gettime(t_time time_code);
void					precise_usleep(long usec, t_global *global);

// UTILS.c
void					clean(t_global *global);
void					wait_all_threads(t_global *global);
bool					all_threads_running(t_mtx *mutex, long *threads,
							long nbr_philo);
void					increase_long(t_mtx *mutex, long *value);
void					desynchronize_philo(t_philo *philo);

// WRITE_PHILO_ACTION.c
void					write_action_debug(t_philo_action action,
							t_philo *philo, long elapsed);
void					write_action(t_philo_action action, t_philo *philo,
							bool debug);
#endif
