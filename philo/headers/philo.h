/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:23:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/11 18:24:04 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define USAGE \
	"Usage: ./philo number_of_philosophers \
time_to_die time_to_eat time_to_sleep [number_of_meals]\n"

typedef struct s_mutex
{
	_Atomic bool	locked;
	pthread_mutex_t	mutex;
}					t_mutex;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meal_counter;
	bool			r_locked;
	bool			l_locked;
	_Atomic bool	eaten;
	_Atomic long	last_meal;
	struct s_mutex	status;
	struct s_mutex	*left_fork;
	struct s_mutex	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	_Atomic int		total_eaten;
	_Atomic bool	someone_died;
	_Atomic bool	printing;
	struct s_philo	*philos;
	struct s_mutex	*forks;
	struct s_mutex	print;
	struct timeval	start;
}					t_data;

// free.c
void				free_data(t_data *data);

// init.c
bool				data_init(t_data *data);
bool				philo_init(t_data *data);

// monitor.c
bool				run_monitor(t_data *data);
void				check_philos(t_data *data);
void				*monitor(void *arg);

// mutex.c
bool				mutex_init(t_mutex *mutex);
bool				mutex_destroy(t_mutex *mutex);
bool				mutex_lock(t_mutex *mutex);
bool				mutex_trylock(t_mutex *mutex);
bool				mutex_unlock(t_mutex *mutex);

// parse.c
bool				parse_args(t_data *data, int ac, char *av[]);

// philosophers.c
int					philosophers(t_data *data);
bool				run_threads(t_data *data);

// routine.c
void				*routine(void *arg);
bool				take_forks(t_philo *philo);
bool				put_forks(t_philo *philo);
bool				philo_eat(t_philo *philo);
bool				philo_sleep(t_philo *philo);
bool				philo_think(t_philo *philo);

// sleep.c
void				ft_mssleep(long time);

// time.c
int					timetoms(struct timeval time);
long				get_time(struct timeval start);

// print.c
bool				print_status(t_philo *philo, char *message);

// utils.c
int					ft_atoi(const char *str);

#endif // PHILO_H
