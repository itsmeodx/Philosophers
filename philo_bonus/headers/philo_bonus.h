/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:27:04 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/26 19:40:28 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define USAGE \
	"Usage: ./philo number_of_philosophers \
time_to_die time_to_eat time_to_sleep [number_of_meals]\n"
# define TAKE "%ld %d has taken a fork\n"
# define EAT "%ld %d is eating\n"
# define SLEEP "%ld %d is sleeping\n"
# define THINK "%ld %d is thinking\n"
# define DIED "%ld %d died\n"

typedef char		*t_string;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_t		monitor;
	int				meal_counter;
	_Atomic bool	died;
	bool			r_locked;
	bool			l_locked;
	bool			s_locked;
	_Atomic bool	eaten;
	long			last_meal;
	t_string		name;
	sem_t			*status;
	sem_t			*left_fork;
	sem_t			*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	pid_t			*pids;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	struct s_philo	*philos;
	sem_t			*starting;
	sem_t			*exitted;
	sem_t			*killall;
	sem_t			*forks;
	sem_t			*print;
	struct timeval	start;
}					t_data;

// exit_bonus.c
void				ft_exit(t_data *data, int status, t_string msg);

// fork_bonus.c
pid_t				ft_fork(t_data *data);

// forks_bonus.c
bool				take_forks(t_philo *philo);
bool				put_forks(t_philo *philo);

// free_bonus.c
void				free_data(t_data *data);

// init_bonus.c
bool				data_init(t_data *data);
t_string			get_sem_name(t_string prefix, int id);
bool				philo_init(t_data *data);

// monitor_bonus.c
bool				run_monitor(t_philo *philo);
bool				check_philo(t_philo *philo);
void				*monitor(void *arg);

// parse_bonus.c
bool				parse_args(t_data *data, int ac, char *av[]);

// philosophers_bonus.c
bool				run_process(t_philo *philo);
int					philosophers(t_data *data);

// print_bonus.c
bool				print_status(t_philo *philo, t_string message);

// routine_bonus.c
void				*routine(void *arg);
bool				philo_eat(t_philo *philo);
bool				philo_sleep(t_philo *philo);
bool				philo_think(t_philo *philo);

// sem_bonus.c
bool				ft_sem_open(sem_t **sem, t_string name, int value);
bool				ft_sem_trywait(sem_t *sem);
long int			ft_sem_getvalue(sem_t *sem);

// sleep_bonus.c
void				ft_mssleep(long time);

// time_bonus.c
int					timetoms(struct timeval time);
long				get_time(struct timeval start);

// utils_bonus.c
size_t				ft_strlen(const t_string s);
int					ft_atoi(const t_string nptr);
t_string			ft_itoa(int m);
t_string			ft_strdup(t_string s);

#endif // PHILO_BONUS_H
