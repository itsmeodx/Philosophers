/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:38 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/27 12:03:36 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	run_process(t_philo *philo)
{
	if (pthread_create(&philo->monitor, NULL, &monitor, philo) != 0)
		return (printf("Error: pthread_create: failed to create monitor\n"),
			(void)false);
	routine(philo);
	if (pthread_join(philo->monitor, NULL) != 0)
		return (printf("Error: pthread_join: failed to join monitor\n"),
			(void)false);
	ft_exit(philo->data, EXIT_SUCCESS, NULL);
}

void	ft_killall(t_data *data, int i)
{
	while (i--)
	{
		if (data->pids[i] != 0)
			kill(data->pids[i], SIGKILL);
	}
	ft_exit(data, EXIT_FAILURE, NULL);
}

int	philosophers(t_data *data)
{
	int		i;
	int		exitted;

	i = -1;
	if (gettimeofday(&data->start, NULL) == -1)
		return (free_data(data), false);
	while (++i < data->philo_count)
	{
		data->pids[i] = ft_fork(data);
		if (data->pids[i] == 0)
			run_process(&data->philos[i]);
	}
	exitted = -1;
	while (ft_sem_trywait(data->killall) == false
		&& exitted != data->philo_count)
	{
		usleep(1 * MS);
		exitted = ft_sem_getvalue(data->exitted);
	}
	if (exitted != data->philo_count)
		ft_killall(data, i);
	return (EXIT_SUCCESS);
}
