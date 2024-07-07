/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:38 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/07 14:31:49 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers(t_data *data)
{
	int		i;

	if (!run_threads(data))
		return (printf("Error: run_threads\n"), EXIT_FAILURE);
	if (!run_monitor(data))
		return (printf("Error: run_monitor\n"), EXIT_FAILURE);
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
	usleep(1000);
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
