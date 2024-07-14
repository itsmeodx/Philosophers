/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:27:04 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/12 21:49:58 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

# define USAGE \
	"Usage: ./philo number_of_philosophers \
time_to_die time_to_eat time_to_sleep [number_of_meals]\n"

typedef struct s_philo
{
	int				id;
	int				meal_counter;
	bool			died;
	bool			r_locked;
	bool			l_locked;
	_Atomic bool	eaten;
	_Atomic long	last_meal;
	sem_t			status;
	sem_t			*left_fork;
	sem_t			*right_fork;
	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
	pid_t			*pids;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	sem_t			someone_died;
	_Atomic bool	printing;
	struct s_philo	*philos;
	sem_t			forks;
	sem_t			print;
	struct timeval	start;
}				t_data;

// exit_bonus.c
void	ft_exit(t_data *data, int status, char *msg);

// fork_bonus.c
pid_t	ft_fork(t_data *data);

// free_bonus.c
void	free_data(t_data *data);

// init_bonus.c
bool	data_init(t_data *data);
bool	philo_init(t_data *data);

// parse_bonus.c
bool	parse_args(t_data *data, int ac, char *av[]);
int	philosophers(t_data *data);

#endif //PHILO_BONUS_H
