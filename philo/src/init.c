/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:55:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/06 20:45:24 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	data_init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->philos || !data->forks)
		return (free_data(data), false);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (free_data(data), false);
	if (gettimeofday(&data->start, NULL) == -1)
		return (free_data(data), false);
	return (true);
}

bool	philo_init(t_data *data)
{
	int	i;

	i = -1;
	memset(data->philos, 0, sizeof(t_philo) * data->philo_count);
	memset(data->forks, 0, sizeof(pthread_mutex_t) * data->philo_count);
	while (++i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].right_fork = &data->forks[i];
		data->philos[i].left_fork = &data->forks[(i + 1) % data->philo_count];
		if (data->philos[i].id == data->philo_count)
		{
			data->philos[i].right_fork = &data->forks[(i + 1)
				% data->philo_count];
			data->philos[i].left_fork = &data->forks[i];
		}
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (free_data(data), false);
		if (pthread_mutex_init(&data->philos[i].counter, NULL) != 0)
			return (free_data(data), false);
	}
	return (true);
}
