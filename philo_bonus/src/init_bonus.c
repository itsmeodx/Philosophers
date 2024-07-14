/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:55:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/12 19:34:47 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	data_init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	data->pids = malloc(sizeof(pid_t) * data->philo_count);
	if (!data->philos || !data->pids
		|| sem_init(&data->forks, 1, data->philo_count) == -1
		|| sem_init(&data->someone_died, 1, 0) == -1
		|| sem_init(&data->print, 1, 1) == -1
		|| gettimeofday(&data->start, NULL) == -1)
		return (free_data(data), false);
	return (true);
}

bool	philo_init(t_data *data)
{
	int	i;

	i = -1;
	memset(data->philos, 0, sizeof(t_philo) * data->philo_count);
	memset(data->pids, 0, sizeof(pid_t) * data->philo_count);
	while (++i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].right_fork = &data->forks;
		data->philos[i].left_fork = &data->forks;
		if (sem_init(&data->philos[i].status, 1, 1) == -1)
			return (free_data(data), false);
	}
	return (true);
}
