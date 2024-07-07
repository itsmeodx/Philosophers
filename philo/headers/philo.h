/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:23:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/06 19:34:23 by oouaadic         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meal_counter;
	_Atomic bool	eaten;
	struct timeval	last_meal;
	pthread_mutex_t	counter;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				meal_counter;
	int				total_eaten;
	_Atomic bool	someone_died;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	struct timeval	start;
}					t_data;

// free.c
void				free_data(t_data *data);

// init.c
bool				data_init(t_data *data);
bool				philo_init(t_data *data);

// monitor.c
bool				run_monitor(t_data *data);
void				*monitor(void *arg);

// parse.c
bool				parse_args(t_data *data, int ac, char *av[]);

// philosophers.c
int					philosophers(t_data *data);
bool				run_threads(t_data *data);

// routine.c
void				*routine(void *arg);
bool				philo_eat(t_philo *philo);
bool				philo_sleep(t_philo *philo);
bool				philo_think(t_philo *philo);

// time.c
long				get_time(struct timeval start);

// print.c
bool				print_status(t_philo *philo, char *status);

// utils.c
int					ft_atoi(const char *str);

#endif // PHILO_H
