/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:38 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/27 11:59:52 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers(t_data *data)
{
	pthread_t	monitor_thread;
	int			i;

	if (!run_threads(data))
		return (printf("Error: run_threads\n"), EXIT_FAILURE);
	if (pthread_create(&monitor_thread, NULL, &monitor, data) != 0)
		return (printf("Error: pthread_create\n"), EXIT_FAILURE);
	if (pthread_join(monitor_thread, NULL) != 0)
		return (printf("Error: pthread_detach\n"), EXIT_FAILURE);
	i = -1;
	while (++i < data->philo_count)
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (printf("Error: pthread_join\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	run_threads(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->philo_count)
	{
		if (i + 1 % 2 != 0)
		{
			if (pthread_create(&data->philos[i].thread, NULL,
					&routine, &data->philos[i]) != 0)
				return (printf("Error: pthread_create\n"), false);
		}
	}
	i = -1;
	while (++i < data->philo_count)
	{
		if (i + 1 % 2 == 0)
		{
			if (pthread_create(&data->philos[i].thread, NULL,
					&routine, &data->philos[i]) != 0)
				return (printf("Error: pthread_create\n"), false);
		}
	}
	return (true);
}
