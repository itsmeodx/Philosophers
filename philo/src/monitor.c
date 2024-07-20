/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:11:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/20 16:14:17 by oouaadic         ###   ########.fr       */
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
		mutex_lock(&data->philos[i].status);
		elapsed_time = get_time(data->start) - data->philos[i].last_meal;
		if (elapsed_time > data->time_to_die
			&& !data->philos[i].eaten)
		{
			data->someone_died = true;
			mutex_lock(&data->print);
			printf("%ld %d died\n", get_time(data->start),
				data->philos[i].id);
			mutex_unlock(&data->print);
			mutex_unlock(&data->philos[i].status);
			break ;
		}
		mutex_unlock(&data->philos[i].status);
	}
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (true)
	{
		if (data->someone_died || data->total_eaten == data->philo_count)
			break ;
		check_philos(data);
		if (data->someone_died || data->total_eaten == data->philo_count)
			break ;
		ft_mssleep(100);
	}
	return (NULL);
}
