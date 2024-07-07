/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:11:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/07 14:37:41 by oouaadic         ###   ########.fr       */
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

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;
	int		total_eaten;

	data = (t_data *)arg;
	while (true)
	{
		i = -1;
		while (++i < data->philo_count)
		{
			pthread_mutex_lock(&data->philos[i].counter);
			if (data->philos[i].meal_counter == data->meals
				&& data->philos[i].eaten == false)
			{
				data->philos[i].eaten = true;
				data->total_eaten++;
			}
			pthread_mutex_unlock(&data->philos[i].counter);
		}
		if (data->total_eaten == data->philo_count)
			break ;
	}
	total_eaten = data->total_eaten;
	return (NULL);
}
