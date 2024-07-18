/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:11:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/18 15:35:31 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	run_monitor(t_data *data)
{
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, &monitor, data) != 0)
		return (printf("Error: pthread_create\n"), false);
	if (pthread_join(monitor_thread, NULL) != 0)
		return (printf("Error: pthread_detach\n"), false);
	return (true);
}

void	check_philos(t_data *data)
{
	int		i;
	long	elapsed_time;

	i = -1;
	while (++i < data->philo_count)
	{
		ft_mssleep(1);
		elapsed_time = get_time(data->start) - data->philos[i].last_meal;
		if (elapsed_time > data->time_to_die
			&& !data->philos[i].eaten)
		{
			data->someone_died = true;
			data->printing = printf("%ld %d died\n", get_time(data->start),
					data->philos[i].id);
			data->printing = printf("current_time: %ld\telapsed time: %ld\t\
			last meal: %ld\ttime to die: %d\n", elapsed_time + \
			data->philos[i].last_meal,
					elapsed_time, data->philos[i].last_meal, data->time_to_die);
			break ;
		}
	}
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!data->someone_died && data->total_eaten != data->philo_count)
	{
		check_philos(data);
		ft_mssleep(100);
	}
	return (NULL);
}
